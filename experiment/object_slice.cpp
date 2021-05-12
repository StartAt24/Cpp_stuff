#include <iostream>
// c++ object slicing happend when a derived class obj is assigned to a base class obj.
using namespace std;

class Base{
protected:
    int i;
public:
    Base(int a){ i = a;}
    virtual void display(){
        cout << "I'm a base class obj, i=" << i << endl;
    }
};

class Derived: public Base{
private:
    int j;
public:
    Derived(int a, int b):Base(a){j=b;}
    virtual void display(){
        cout << "I'm a derived class obj, i=" << i<< ",j="<<j << endl;
    }
};

int main(){
    Base b(1);
    Derived d(2,3);
    b.display(); // output: I am Base class object, i = 1
    d.display(); // output: I am Base class object, i = 2
    return 0;
}