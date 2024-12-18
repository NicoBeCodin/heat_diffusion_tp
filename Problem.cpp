#include "Problem.h"
#include "GaussSeidel.h"
#include "IScheme.h"
#include "Jacobi.h"




Problem::Problem(IMesh *mesh, int max_iterations)
    : mesh(mesh), max_iterations(max_iterations) {
  if (!mesh) {
    throw std::invalid_argument("Mesh cannot be null");
  }
}

Problem::~Problem() { delete mesh; }


//Initial condition 
double funcInitialCondition(double x) {
  if (x > 0.5)
    return 15.0;
  else
    return 30.0;
};

void Problem::solve(bool performance_mode, bool useJacobi) {
  std::cout << "--- Solve problem --- " << std::endl;

  Timer total_time("Total solve time");
  total_time.start();

  Variable u_k(mesh, "u_k");
  Variable u_kp1(mesh, "u_kp1");
  Variable u_k_start(mesh, "u_k_start");
  

  equation.compute_initial_condition(u_k, mesh, funcInitialCondition);
  equation.compute_initial_condition(u_k_start, mesh, funcInitialCondition);

  // print initial condition
  u_k_start.setName("initialCondition");
  if (!performance_mode) {
    u_k.print(false);
  }

  equation.compute_boundary_conditions(u_kp1, 30, 15);



  int i;
  for (i = 0; i <= max_iterations; ++i) {
    if (!performance_mode) {
      std::cout << "--- Iterative method iteration: " << i << " ---"
                << std::endl;
    }
    if (useJacobi){
    equation.compute_for_scheme<Jacobi>(mesh, u_k, u_kp1,
                                             performance_mode);
    } else {
    equation.compute_for_scheme<GaussSeidel>(mesh, u_k, u_kp1,
                                             performance_mode);
    }
    if (has_converged(u_k, u_kp1, 1e-06))
      break;
    u_k.updateValues(u_kp1);
  }

  total_time.stop();
  total_time.print();

  std::cout << "Number of iterations needed: " << i << std::endl;
  std::string schemeName = (useJacobi) ? "Jacobi" : "GaussSeidel";
  u_kp1.setName(schemeName);
  u_kp1.print();

    
  std::cout << "\nExact solution: " << std::endl;
  Variable exact_solution = equation.compute_exact_solution(u_k_start, mesh);
  exact_solution.setName("exactSolution");
  exact_solution.print();
  
}

//Two solves with different schemes in parallel
void Problem::solve_parallel(bool performance_mode) {
  std::cout << "--- Solve problem in parallel --- " << std::endl;


  //Start the total time
  Timer total_time("Total solve time");
  total_time.start();

  auto jacobi_future =std::async(std::launch::async,[this, performance_mode](){
    

    Timer jacobi_time("Jacobi solve time");
    jacobi_time.start();

    Variable u_k(mesh, "u_k");
    Variable u_kp1(mesh, "u_kp1");

    // Lambda function for quick declaration
    equation.compute_initial_condition(u_k, mesh, funcInitialCondition);
    // u_k.print();
    // print initial condition
    u_k.setName("initialCondition");
    if (!performance_mode) {
      u_k.print(false);
    }

    equation.compute_boundary_conditions(u_kp1, 30, 15);

    int i;
    for (i = 0; i <= max_iterations; ++i) {
      if (!performance_mode) {
        std::cout << "--- Iterative method iteration: " << i << " ---"
                  << std::endl;
      }
      equation.compute_for_scheme<Jacobi>(mesh, u_k, u_kp1,
                                              performance_mode);
      if (has_converged(u_k, u_kp1, 1e-06))
        break;
      u_k.updateValues(u_kp1);
    }

    jacobi_time.stop();
    jacobi_time.print();

    std::cout << "Number of iterations needed: " << i << std::endl;
    u_kp1.setName("u_kp1_Jacobi");
    u_kp1.print();
    std::cout<<std::endl;


  });

  auto gauss_future= std::async(std::launch::async,[this, performance_mode](){
    

    Timer gauss_time("Gauss solve time");
    gauss_time.start();

    Variable u_k(mesh, "u_k");
    Variable u_kp1(mesh, "u_kp1");

    // Lambda function for quick declaration
    equation.compute_initial_condition(u_k, mesh, funcInitialCondition);
    // u_k.print();
    // print initial condition
    u_k.setName("initialCondition");
    if (!performance_mode) {
      u_k.print(false);
    }

    equation.compute_boundary_conditions(u_kp1, 30, 15);

    int i;
    for (i = 0; i <= max_iterations; ++i) {
      if (!performance_mode) {
        std::cout << "--- Iterative method iteration: " << i << " ---"
                  << std::endl;
      }
      equation.compute_for_scheme<GaussSeidel>(mesh, u_k, u_kp1,
                                              performance_mode);
      if (has_converged(u_k, u_kp1, 1e-06))
        break;
      u_k.updateValues(u_kp1);
    }

    gauss_time.stop();
    gauss_time.print();

    std::cout << "Number of iterations needed: " << i << std::endl;
    u_kp1.setName("u_kp1_GaussSeidel");
    u_kp1.print();

    std::cout<<std::endl;

  });
  
  jacobi_future.wait();
  gauss_future.wait();

  total_time.stop();
  total_time.print();

}

bool Problem::has_converged(Variable &u_k, Variable &u_kp1, double epsilon) {
  double max_diff = 0.0;
  for (int i = 0; i < u_k.size(); ++i) {
    double diff = std::abs(u_kp1[i] - u_k[i]);
    max_diff = std::max(max_diff, diff);
  }
  return max_diff < epsilon;
}


double Problem::compute_residual(Variable &u, IMesh *mesh) {
  double max_residual = 0.0;
  for (int i = 1; i < mesh->getNumberOfPoints() - 1; ++i) {
    double residual = std::fabs(2 * u[i] - u[i - 1] - u[i + 1]);
    max_residual = std::max(max_residual, residual);
  }
  return max_residual;
}