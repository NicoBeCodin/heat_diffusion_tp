Below is a sample `README.md` file you can adapt for your project. Adjust names, paths, and commands as needed, depending on your actual project structure and configuration.

---

# Heat Equation Simulation Project

This project provides a C++ implementation of a 1D stationary heat equation solver using iterative methods such as Jacobi and Gauss-Seidel. It demonstrates an object-oriented approach, introduces a flexible software architecture, and progressively adds features like mesh discretization, boundary conditions, iterative solvers, solution validation, performance measurement, and parallelization.

## Overview

### Equation

We focus on the 1D Laplace equation:

\[
\Delta u = 0 \quad \text{on } [0,1]
\]

with Dirichlet boundary conditions \( u(0)=T_1 \) and \( u(1)=T_2 \).

### Methods

1. **Jacobi Iteration**:
   \[
   u_i^{k+1} = \frac{u_{i-1}^k + u_{i+1}^k}{2}
   \]

2. **Gauss-Seidel Iteration**:
   \[
   u_i^{k+1} = \frac{u_{i-1}^{k+1} + u_{i+1}^k}{2}
   \]

We also implement a reference exact solution for a linear temperature profile:
\[
u_{\text{exact}}(x) = (T_2 - T_1) x + T_1.
\]

## Features

- **Object-Oriented Design**: Classes for `Problem`, `Equation`, `IMesh`, `UniformMesh`, and `Variable` manage data and computations.
- **Flexible Initial and Boundary Conditions**: Functions or lambdas can define the initial temperature field.
- **Validation**: Comparison against the exact solution and residual calculation to ensure correctness.
- **Performance Measurement**: A `Timer` class to measure execution time of the entire solve and iterative steps.
- **Parallelization**:
  - **Coarse-Grain Parallelization**: Using `std::thread` or `std::async` to run separate iterative methods in parallel.
  - **Fine-Grain Parallelization**: Using C++17 parallel STL algorithms (`std::for_each(std::execution::par, ...)`) to parallelize loops within the Jacobi scheme.
- **Export of Results**: Variables can be printed to `.data` files for plotting (e.g., with Gnuplot).

## Dependencies

- **C++17 or newer**: The code relies on modern C++ features.
- **CMake**: For build configuration.
- **Intel TBB**: Required for parallel STL execution policies.
- **Gnuplot (optional)**: For plotting the results.

On Ubuntu/Debian:
```bash
sudo apt update
sudo apt install cmake libtbb-dev gnuplot
```

## Building

Run the following commands in the project directory:

```bash
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

Adjust `-DCMAKE_BUILD_TYPE` and the `find_package` lines in `CMakeLists.txt` as needed.

## Running

After building:

```bash
./simulation
```

Command-line arguments can be added if you implemented them (e.g., for choosing mesh parameters or solver type). If not, the solver will run with default parameters specified in the code.

## Plotting Results

The solver writes `.data` files (e.g., `Variable_u_kp1.data`, `Variable_exactSolution.data`) into the parent folder of `build`. Use Gnuplot to plot them:

```gnuplot
gnuplot> plot "../Variable_u_kp1.data" with lines title "Numerical", \
              "../Variable_exactSolution.data" with linespoints title "Exact"
```

This allows you to visually compare the numerical solution with the exact solution.

## Performance Tips

- Run in `Release` mode for accurate performance measurements.
- Disable extra console output when measuring performance (`performance_mode`).
- Experiment with both sequential and parallel execution policies by toggling between `std::execution::seq` and `std::execution::par`.

## Code Structure

- **main.cpp**: Entry point of the program, creates and configures a `Problem` instance, then calls `solve()` or `solve_parallel()`.
- **Problem.h / Problem.cpp**: Manages the resolution process, including iteration, convergence checks, and calling the `Equation` methods.
- **Equation.h / Equation.cpp**: Defines `compute`, `compute_initial_condition`, `compute_boundary_conditions`, and `compute_exact_solution`.
- **IMesh.h / UniformMesh.h/ .cpp**: Interface and implementation for spatial discretization.
- **Variable.h / Variable.cpp**: Handles storage and indexing of the solution vector.
- **Timer.h / Timer.cpp**: Measures execution time.
- **Jacobi.h / Jacobi.cpp** and **GaussSeidel.h / GaussSeidel.cpp**: Implement iterative solvers.

## Future Extensions

- Introduce more sophisticated boundary conditions or sources.
- Explore more advanced parallelization techniques or use distributed computing frameworks.
- Compare different iteration schemes (e.g., SOR, CG methods) or add preconditioning.

## Contact & License

This is a didactic project from a series of TD sessions focused on HPC, OOP design, and numerical methods. Feel free to reuse and adapt the code as you wish. If you have questions or suggestions, please contact the maintainers or open an issue.