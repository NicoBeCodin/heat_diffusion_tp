#ifndef ISCHEME_H
#define ISCHEME_H


class IMesh;     // Forward declaration of IMesh
class Variable;  // Forward declaration of Variable

class IScheme {
public:
    
    virtual void compute_iteration(IMesh* mesh, Variable& u_k, Variable& u_kp1) = 0;
    virtual ~IScheme() = default;
};


#endif