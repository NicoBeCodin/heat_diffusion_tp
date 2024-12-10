#include "GaussSeidel.h"

void GaussSeidel::compute_iteration(IMesh* mesh, Variable& u_k, Variable& u_kp1) {
    for (int i = 1; i < mesh->getNumberOfPoints() - 1; ++i) {
        // Gauss-Seidel uses updated values of u_kp1 in the calculation
        u_kp1[i] = 0.5 * (u_kp1[i - 1] + u_k[i + 1]);
    }
    
}
