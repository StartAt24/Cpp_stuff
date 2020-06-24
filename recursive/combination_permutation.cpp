#include <iostream>
using namespace std;

void swap(int* arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// 排列
void permutation(int* arr, int start, int end){
    if(start == end){
        for(int i=0; i<end; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // 从start开始的意思是 第一个数字 就取原来的数。
    for(int i=start; i<end;i++){
        swap(arr, i, start);
        permutation(arr, start+1, end);
        swap(arr, i, start);
    }
    return; 
}

void combination(int* arr, int start, int end){

}


int main(int argc, char** argv){
    int arr[3] = {1,2,3};
    permutation(arr, 0, 3);
    return 0;
}
