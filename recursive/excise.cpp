#include <iostream>
#include <map>
using namespace std;

std::map<int, int> history;
// 爬楼梯
int climb(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    if(history.find(n)!=history.end())
        return history.at(n);
    
    int ret = climb(n-1) + climb(n-2);
    history.insert(make_pair(n, ret));
    return ret;
}


int main(){
    cout << climb(3);
}