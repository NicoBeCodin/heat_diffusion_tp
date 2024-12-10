cmake_minimum_required(VERSION 3.10)

project(heat_equation)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(simulation main.cpp Equation.cpp Problem.cpp UniformMesh.cpp Variable.cpp Jacobi.cpp GaussSeidel.cpp Timer.cpp)

enable_testing()
add_test(NAME structure_test COMMAND simulation)

find_package(Threads)
find_package(TBB)
target_link_libraries(simulation Threads::Threads TBB::tbb)
