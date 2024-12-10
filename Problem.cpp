#include "Problem.h"
#include "GaussSeidel.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <thread>
#include <future>
#include "IMesh.h"
#include "Jacobi.h"
#include "Timer.h"

Problem::Problem(IMesh *mesh, int max_iterations)
    : mesh(mesh), max_iterations(max_iterations) {
  if (!mesh) {
    throw std::invalid_argument("Mesh cannot be null");
  }
}

Problem::~Problem() { delete mesh; }

double funcInitialCondition(double x) {
  if (x > 0.5)
    return 15.0;
  else
    return 30.0;
};

void Problem::solve(bool performance_mode) {
  std::cout << "--- solve problem --- " << std::endl;

  Timer total_time("Total solve time");
  total_time.start();

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

  total_time.stop();
  total_time.print();

  std::cout << "Number of iterations needed: " << i << std::endl;
  u_kp1.setName("GaussSeidel");
  u_kp1.print();

  if (!performance_mode || true) {
    std::cout << "Exact solution: " << std::endl;
    Variable exact_solution = equation.compute_exact_solution(u_k, mesh);
    exact_solution.setName("exactSolution");
    exact_solution.print();
  }
}

// void Problem::solve_parallel(bool performance_mode) {
//   std::cout << "--- solve problem in parallel --- " << std::endl;

//   Timer total_time("Total solve time");
//   total_time.start();




//   std::thread jacobi_thread([this, performance_mode](){
//     std::cout << "--- solve problem --- " << std::endl;

//   Timer jacobi_time("Jacobi solve time");
//   jacobi_time.start();

//   Variable u_k(mesh, "u_k");
//   Variable u_kp1(mesh, "u_kp1");

//   // Lambda function for quick declaration
//   equation.compute_initial_condition(u_k, mesh, funcInitialCondition);
//   // u_k.print();
//   // print initial condition
//   u_k.setName("initialCondition");
//   if (!performance_mode) {
//     u_k.print(false);
//   }

//   equation.compute_boundary_conditions(u_kp1, 30, 15);

//   int i;
//   for (i = 0; i <= max_iterations; ++i) {
//     if (!performance_mode) {
//       std::cout << "--- Iterative method iteration: " << i << " ---"
//                 << std::endl;
//     }
//     equation.compute_for_scheme<Jacobi>(mesh, u_k, u_kp1,
//                                              performance_mode);
//     if (has_converged(u_k, u_kp1, 1e-06))
//       break;
//     u_k.updateValues(u_kp1);
//   }

//   jacobi_time.stop();
//   jacobi_time.print();

//   std::cout << "Number of iterations needed: " << i << std::endl;
//   u_kp1.setName("u_kp1_Jacobi");
//   u_kp1.print();
//   std::cout<<std::endl;


//   });



//   std::thread gauss_thread([this, performance_mode](){
//     std::cout << "--- solve problem --- " << std::endl;

//   Timer gauss_time("Gauss solve time");
//   gauss_time.start();

//   Variable u_k(mesh, "u_k");
//   Variable u_kp1(mesh, "u_kp1");

//   // Lambda function for quick declaration
//   equation.compute_initial_condition(u_k, mesh, funcInitialCondition);
//   // u_k.print();
//   // print initial condition
//   u_k.setName("initialCondition");
//   if (!performance_mode) {
//     u_k.print(false);
//   }

//   equation.compute_boundary_conditions(u_kp1, 30, 15);

//   int i;
//   for (i = 0; i <= max_iterations; ++i) {
//     if (!performance_mode) {
//       std::cout << "--- Iterative method iteration: " << i << " ---"
//                 << std::endl;
//     }
//     equation.compute_for_scheme<GaussSeidel>(mesh, u_k, u_kp1,
//                                              performance_mode);
//     if (has_converged(u_k, u_kp1, 1e-06))
//       break;
//     u_k.updateValues(u_kp1);
//   }

//   gauss_time.stop();
//   gauss_time.print();

//   std::cout << "Number of iterations needed: " << i << std::endl;
//   u_kp1.setName("u_kp1_GaussSeidel");
//   u_kp1.print();

//   std::cout<<std::endl;

//   });


//   jacobi_thread.join();
//   gauss_thread.join();

//   total_time.stop();
//   total_time.print();

// }

void Problem::solve_parallel(bool performance_mode) {
  std::cout << "--- solve problem in parallel --- " << std::endl;

  Timer total_time("Total solve time");
  total_time.start();




  auto jacobi_future =std::async(std::launch::async,[this, performance_mode](){
    std::cout << "--- solve problem --- " << std::endl;

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
    std::cout << "--- solve problem --- " << std::endl;

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