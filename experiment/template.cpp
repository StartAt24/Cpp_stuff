#include <iostream>
#include <string>
using namespace std;

// 模板的参数类型:
// 1.类型
// 2.非类型：a.左值引用 b.指针 c.枚举 d.Int


template<string& temp>
void s(){
    cout << temp << endl;
}

template<string* temp>
void t(){
    cout << *temp << endl;
}

string global = "global";
int main(){
    s<global>();
    t<&global>();
}
// 所以模板的这些非类型参数有什么用呢？
template<int>
void fun1(){}

template<int*>
void func2(){}

template<int&>
void func3(){}

template<char*>
void func4(){}

template<char>
void func5(){}
