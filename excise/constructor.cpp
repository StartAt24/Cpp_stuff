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
    cout << "my son is ill today, he vomits serval times. His mon and I took him to the hospital" << endl;
    cout << "I want get rank 2900 using protect paladin."<< endl;
    cout << "I'm gona to make some video about wow." << endl;
}