#include <iostream>

int tadd_ok(int a, int b){
    if(a>0 && b>0 && a+b<0)
        return 0;
    if(a<0 && b<0 && a+b>0)
        return 0;
    return 1;
}

// 以8bit整数为例 取值范围是 [-128, 127]. 不是对称的，所以说 TMin = -TMin, 因为溢出了。所以测试整数的时候一定要测试 TMin!!!
int main(){
    int8_t s = -128;
    int8_t b = -s;
    std::cout <<(int)b << std::endl;
    return 0;
}
