#include <iostream>
#include <array>
using namespace  std;


// 4，5，6，3，2，1
template<typename T, int cap>
void bubble_sort(array<T, cap>& in){
    if(in.empty() || in.size() == 1)
        return;
    
    const size_t size = in.size();

    auto swap_val_func = [&](int idx1, int idx2){
        T temp = in[idx1];
        in[idx1] = in[idx2];
        in[idx2] = temp;
    };

    for(auto i=0; i<size; i++){
        bool sort = false;
        for(auto j=i; j<size; j++){
            if(in[i] < in[j]){
                swap_val_func(i, j);
                sort = true;
            }
        }
        if(!sort)
            return;
    }
    return;
}

template<typename T, int cap>
void print(const array<T, cap>& in){
    for(const auto& v: in){
        cout << v <<" ";
    }
    cout << "\n";
}

int main(){
    array<int, 6> arr = {4,5,6,3,2,1};
    print<int , arr.size()>(arr);
    bubble_sort<int, arr.size()>(arr);
    print<int , arr.size()>(arr);
    return 0;
}
