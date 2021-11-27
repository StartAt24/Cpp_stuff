#include <iostream>

class PrivateDestructor{
public:
    PrivateDestructor(){
    }

private:
    ~PrivateDestructor(){
    }
};

class ProctectedDestructor{
    public:
    ProctectedDestructor(){}
    protected:
    ~ProctectedDestructor(){}
};
