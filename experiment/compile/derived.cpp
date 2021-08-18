#include "base.h"
#include "derived.h"
#include <iostream>
using namespace std;

void Derived::interface(){
    cout << "derived" << endl;
}

int main(){
    cout << "entry" << endl;
}