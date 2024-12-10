#ifndef EQUATION_H
#define EQUATION_H
#include <iostream>
#include <iomanip>
#include <functional>
#include "IMesh.h"
#include "Variable.h"
#include "Jacobi.h"
#include "GaussSeidel.h"


class Equation {
public:
    template <typename Scheme>
    void compute_for_scheme(IMesh* mesh, Variable& u_k, Variable& u_kp1, bool performance_mode=true);


    //template <typename Func>
    void compute_initial_condition(Variable& u, IMesh* mesh, double (*func)(double) );
    void compute_boundary_conditions(Variable& u, double T1, double T2);
    Variable compute_exact_solution(Variable& u, IMesh* mesh);

};


template <typename Scheme>
void Equation::compute_for_scheme(IMesh* mesh, Variable& u_k, Variable& u_kp1, bool performance_mode){
    //Loop through all points of mesh
    
    // scheme.compute_iteration(mesh, u_k, u_kp1);
    Scheme::compute_iteration(mesh, u_k, u_kp1);
    for (size_t i =0; i<mesh->getNumberOfPoints(); ++i){
        if (!performance_mode){
            std::cout<<"u_k["<<  i<<"] = "<< u_k[i]<< std::fixed<<std::setprecision(5)<<" u_kp1["<< i<<"] = "<<u_kp1[i]<< std::fixed<<std::setprecision(5)<<std::endl;
        }
        
    }
}



#endif