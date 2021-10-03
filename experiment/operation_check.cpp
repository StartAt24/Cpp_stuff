#include <iostream>

int tadd_ok(int a, int b){
    if(a>0 && b>0 && a+b<0)
        return 0;
    if(a<0 && b<0 && a+b>0)
        return 0;
    return 1;
}

