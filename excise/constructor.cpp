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

class Marrage{
    public:
    Marrage(){}
    void say(){
        cout << "best friend get married"<<endl;
    }
};