#include <iostream>
using namespace std;

class Base{
public:
    void templateFunc(){
        funcA();
        cout << b_ << endl;
        funcB();
    };
    virtual void funcA() = 0;
    virtual void funcB() = 0;
private:
    int b_=3;
};


class A: public Base{
public:
    A(int a):a_(a){}
    void funcA(){
        cout<< "A A:"<< a_ <<endl;
    }
    void funcB(){
        cout<< "B B:"<< a_ <<endl;
    }
private:
    int a_;
};

int main(){
    Base* b = new A(3);

    b->templateFunc();
}