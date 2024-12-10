#include "Problem.h"
#include "UniformMesh.h"


int main(){

    double x_min = 0.0;
    double x_max = 1.0;
    double dx = 0.01;

    IMesh* mesh = new UniformMesh(x_min, x_max, dx);
    Problem problem(mesh,1000000);
    
    problem.solve_parallel();

    return 0;
}