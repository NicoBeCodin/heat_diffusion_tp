#ifndef VARIABLE_H
#define VARIABLE_H

#include "IMesh.h"
#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <iomanip>


class Variable{
private: 
    std::vector<double> values;
    IMesh* mesh;
    std::string m_name;

public:
    Variable(IMesh* mesh, std::string name);
    double& operator[](int index);
    int size() const;
    void setName(std::string m_name);
    void print(bool saveFile=true);
    void updateValues(Variable u_kp1);



};

#endif