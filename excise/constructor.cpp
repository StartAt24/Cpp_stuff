#include <iostream>
using namespace std;

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

int main (){
    cout << "shutiao is sleeping." << endl;
    cout << "shutiao is sleeping in the sun." << endl;
    cout << "shutiao is sleeping in the sun another day." << endl;
}