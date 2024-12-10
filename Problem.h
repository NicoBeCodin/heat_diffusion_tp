#ifndef PROBLEM_H
#define PROBLEM_H

#include "Equation.h"
#include "IMesh.h"


class Problem{
private:
    Equation equation;
    IMesh* mesh;
    int max_iterations;

public: 
    Problem(IMesh* mesh, int max_iterations);
    ~Problem();
    void solve(bool performance_mode =true);
    bool has_converged(Variable& u_k, Variable& u_kp1, double epsilon = 1e-05);
    double compute_residual(Variable& u, IMesh* mesh);
    void solve_parallel(bool performance_mode=true);

};

#endif