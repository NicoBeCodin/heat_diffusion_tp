#ifndef GAUSS_SEIDEL_H
#define GAUSS_SEIDEL_H

#include "IScheme.h"
#include "IMesh.h"
#include "Variable.h"

class GaussSeidel {
public:
    static void compute_iteration(IMesh* mesh, Variable& u_k, Variable& u_kp1);
};

#endif
