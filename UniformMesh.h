#ifndef UNIFORMMESH_H
#define UNIFORMMESH_H

#include "IMesh.h"

class UniformMesh : public IMesh {
private:
    double x_min;
    double x_max;
    double dx;
    int num_points;

public:
    UniformMesh(double x_min, double x_max, double dx);
    int getNumberOfPoints() const override;
    double getPosition(int index) const override;
    double x_i(int index)const;

};
#endif
