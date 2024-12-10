#ifndef JACOBI_H
#define JACOBI_H

#include "IScheme.h"
#include "IMesh.h"
#include "Variable.h"

class Jacobi {
public:
    static void compute_iteration(IMesh* mesh, Variable& u_k, Variable& u_kp1);
};

#endif
