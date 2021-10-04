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