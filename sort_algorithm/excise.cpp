#include <iostream>
#include <array>
using namespace  std;


// 4，5，6，3，2，1
template<typename T, int cap>
void select_sort(array<T, cap>& in){
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

template<typename T,int cap>
void insert_sort(array<T, cap>& in){
    size_t size = in.size();
    if(size == 0 || size == 1)
        return;
    for(auto i=0;i<size;i++){
        T val = in[i];
        size_t j = i-1;
        for( ;j>=0; j--){
            if(in[j] > val)
                in[j+1] = in[j];
            else
                break;
        }
        in[j+1] = val;
    }
}

int main(){
    array<int, 6> arr = {4,5,6,3,2,1};
    print<int , arr.size()>(arr);
    insert_sort<int, arr.size()>(arr);
    print<int , arr.size()>(arr);
    return 0;
}
