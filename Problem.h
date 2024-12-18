#ifndef PROBLEM_H
#define PROBLEM_H

#include "Equation.h"
#include "IMesh.h"
#include "GaussSeidel.h"
#include "Jacobi.h"
#include "Timer.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <future>



class Problem{
private:
    Equation equation;
    IMesh* mesh;
    int max_iterations;

public: 
    Problem(IMesh* mesh, int max_iterations);
    ~Problem();
    void solve(bool performance_mode =true, bool useJacobi= true);
    bool has_converged(Variable& u_k, Variable& u_kp1, double epsilon = 1e-05);
    double compute_residual(Variable& u, IMesh* mesh);
    void solve_parallel(bool performance_mode=true);

};

#endif