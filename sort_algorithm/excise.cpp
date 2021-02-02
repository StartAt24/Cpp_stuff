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

void merge(int* arr, int l, int mid, int r){
    int size_l = mid-l+1;
    int size_r = r-mid;
    int L[size_l], R[size_r];

    auto copy_arr = [](int* src, int* dst, int start, int end){
        int idx = 0;
        for(auto i= start; i<=end; i++){
            dst[idx] = src[i];
            ++idx;
        }
    };
    copy_arr(arr, L, l, mid);
    copy_arr(arr, R, mid+1, r);

    cout<< "mid\n";
    int i=0,j=0,ori_idx=l;
    while(i<size_l && j <size_r){
        if(L[i] < R[j]){
            arr[ori_idx] = L[i];
            ++i;
        }else{
            arr[ori_idx] = R[j];
            ++j;
        }
        ++ori_idx;
    }
    while(i<size_l){
        arr[ori_idx] = L[i];
        ++ori_idx;
        ++i;
    }
    while(j<size_r){
        arr[ori_idx] = R[j];
        ++ori_idx;
        ++j;
    }
}

void merge_recursive(int* arr, int l, int r){
    if(l>=r)
        return;
    // avoid stack overflow
    int mid = l + (r-l)/2;
    merge_recursive(arr, l, mid);
    merge_recursive(arr, mid+1, r);
    merge(arr, l, mid, r);
}

void merge_sort(int* arr, int len){
    merge_recursive(arr, 0, len-1);
}

void print_arr(int* arr, int len){
    for(int i=0; i<len; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main(){
    // array<int, 6> arr = {4,5,6,3,2,1};
    // print<int , arr.size()>(arr);
    // insert_sort<int, arr.size()>(arr);
    // print<int , arr.size()>(arr);
    int arr[10]= {1,3,4,0,6,2,4,1,10,22};
    merge_sort(arr, 10);
    print_arr(arr, 10);
    return 0;
}
