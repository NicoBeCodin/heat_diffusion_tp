#include "Jacobi.h"
#include "Variable.h"
#include <algorithm>
#include <numeric>
#include <execution>


void Jacobi::compute_iteration(IMesh* mesh, Variable& u_k, Variable& u_kp1) {
    // for (int i = 1; i < mesh->getNumberOfPoints() - 1; ++i) {
    //     u_kp1[i] = 0.5 * (u_k[i - 1] + u_k[i + 1]);
    // }   
    
    //Parallelize
    int N = mesh->getNumberOfPoints();
    std::vector<int> indices(N-2);
    std::iota(indices.begin(), indices.end(), 1);
    std::for_each(std::execution::par, indices.begin(), indices.end(), [&](int i) {
        u_kp1[i] = 0.5*(u_k[i-1] + u_k[i+1]);

    });


}
