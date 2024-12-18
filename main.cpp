#include <iostream>
#include <string>
#include "Problem.h"
#include "UniformMesh.h"

int main() {
    double x_min = 0.0;
    double x_max = 1.0;
    double dx = 0.01;
    int max_iterations = 100000;

    IMesh* mesh = new UniformMesh(x_min, x_max, dx);
    Problem problem(mesh, max_iterations);

    std::string mode_choice;
    std::cout << "Choose mode: (1) solve  (2) solve_parallel" << std::endl;
    std::cin >> mode_choice;

    if (mode_choice == "1") {
        // User chose solve()

        std::string scheme_choice;
        std::cout << "Choose scheme: (1) Jacobi  (2) GaussSeidel" << std::endl;
        std::cin >> scheme_choice;

        bool useJacobi = false;
        if (scheme_choice == "1") {
            useJacobi = true; // Jacobi
        } else if (scheme_choice == "2") {
            useJacobi = false; // GaussSeidel
        } else {
            std::cerr << "Invalid scheme choice. Defaulting to GaussSeidel." << std::endl;
        }

        // performance_mode = true (no prints), change if you want
        problem.solve(true, useJacobi);

    } else if (mode_choice == "2") {
        // User chose solve_parallel()
        // performance_mode can remain true or false as desired
        problem.solve_parallel(true);
    } else {
        std::cerr << "Invalid mode choice. Exiting." << std::endl;
    }

    return 0;
}
