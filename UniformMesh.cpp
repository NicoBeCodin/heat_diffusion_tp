#include "UniformMesh.h"
#include <stdexcept>
#include <iostream>

UniformMesh::UniformMesh(double x_min, double x_max, double dx):x_min(x_min), x_max(x_max), dx(dx){
    if (dx <= 0.0 || (x_min >= x_max)) {
        throw std::invalid_argument("Invalid mesh parameters");
    }
    
    num_points = static_cast<int>((x_max-x_min)/dx)+1;    
}

int UniformMesh::getNumberOfPoints() const{
    return num_points;
}

double UniformMesh::getPosition(int index)const {
    if (index < 0 || index >=num_points){
        throw std::out_of_range("Index out of range");  
    }
    

    return (double(index)*dx  + x_min);
}

double UniformMesh::x_i(int index) const {
    return (index * dx + x_min);
}