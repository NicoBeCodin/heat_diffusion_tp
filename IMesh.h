#ifndef IMESH_H
#define IMESH_H

class IMesh{
    public:
        virtual ~IMesh() =default;
        virtual int getNumberOfPoints() const = 0;
        virtual double getPosition(int index) const = 0;
        virtual double x_i(int i) const = 0;
        

};

#endif