#include "Variable.h"


Variable::Variable(IMesh * mesh, std::string name) : mesh(mesh), m_name(name){
    if (!mesh) throw std::invalid_argument("Mesh cannot be null");
    values.resize(mesh->getNumberOfPoints()); //Do i need to create Mesh::x_size() ?
}

double& Variable::operator[](int index){
    return values[index];
}

int Variable::size() const {
    return values.size();
} 
void Variable::setName(std::string name){
    m_name = name;
}
void Variable::print(bool saveFile){

    if (saveFile){
        std::string filename = "../Variable_" + m_name + ".data";

        std::ofstream file(filename);
        if (!file.is_open()){
            std::cerr<<"Can't open file!!"<<std::endl; 
            return;
        }
        for (int i = 0; i < size(); ++i) {
            double x = mesh->getPosition(i);
            file << std::fixed << std::setprecision(4) << x << " " << values[i] << "\n";
        }
        file.close();
        std::cout<< "Variable " << m_name << " written to: " << filename<<std::endl;

    }


    std::cout<< "Variable name: "<< m_name<<std::endl;
    for (int i =0; i<values.size(); ++i){
        std::cout<<i<< " : " << values[i]<< std::endl;
    }


}
void Variable::updateValues(Variable u_kp1){
    for (int i = 0; i<u_kp1.size(); ++i){
        values[i] = u_kp1[i];
    }
}
