#include "Equation.h"

//Initial condition
void Equation::compute_initial_condition(Variable &u, IMesh *mesh, double (*func)(double))
{
    for (int i = 0; i < mesh->getNumberOfPoints(); ++i)
    {
        double x_i = mesh->getPosition(i);
        u[i] = func(x_i);
    }
}

//Boundary condition
void Equation::compute_boundary_conditions(Variable &u, double T1, double T2)
{
    u[0] = T1;
    u[u.size() - 1] = T2;
}


//Exact solution is linear
Variable Equation::compute_exact_solution(Variable &u, IMesh *mesh)
{
    Variable u_ref(mesh, "exact_solution");
    int nb = mesh->getNumberOfPoints();
    double step = 1.0 / ((double)nb - 1);

    double t_2 = u[u.size() - 1];
    double t_1 = u[0];

    for (int i = 0; i < u.size(); ++i)
    {
        u_ref[i] = step * i * (t_2 - t_1) + t_1;
    }
    return u_ref;
}
