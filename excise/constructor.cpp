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
    cout << "Todoy overtime two 26+ keys" << endl;
    cout << "forget to push yesterday" << endl;
    cout << "draw a green box" << endl;
    cout << "draw a green box again, yy+p" << endl;
    cout << "draw a green box again, yy+p" << endl;
    cout << "the last day of 2021." << endl;
    cout << "first day of 2022" << endl;
}