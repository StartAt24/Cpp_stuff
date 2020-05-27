#include <iostream>
#include <limits>

using namespace std;

void print(int* arr, int len){
    for(auto i=0;i<len;i++){
        cout << "index: "<<i << ",value: "<< arr[i] << endl;
    }
}

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSortRecursive(int*& arr, int start, int end){
    if(start >= end) {
        return;
    }
    int mid = (end+start)/2;

    mergeSortRecursive(arr, start, mid);
    mergeSortRecursive(arr, mid+1, end);
    // 不要传进去多个指针 修改原始的值
    merge(arr, start, mid, end);
}

void mergeSort(int* &arr, int len){
    mergeSortRecursive(arr, 0, len-1);
}

// 时间复杂度 O(n), 空间复杂度 O(1)
void bubbleSort(int* & arr, int len){
    if(len<=1)
        return;
    auto limit = len-1;
    while(limit>1){
        bool flag = false;
        for(auto i=0; i<limit; i++){
            // 如果低位的比高位的大 则交换两者
            if(arr[i]>arr[i+1]){
                auto temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                flag = true;
            }
        }
        // 如果某一次 没有交换 说明已经排序完成了。
        if(!flag)
            break;
        limit--;
    }

}

// 插入排序
void insertionSort(int *&arr, int len){
    if(len<=1) return;

    for(auto i=1;i<len;i++){
        auto val = arr[i];
        auto index = i-1;

        while(index >=0){
            // move data
            if(arr[index] > val){
                arr[index+1] = arr[index];
                index --;
            }else{
                break;
            }
        }
        arr[index+1] = val;
    }
}

// 选择排序
void selectionSort(int* &arr, int len){

    for(auto i=0; i<len;i++){
        auto temp = arr[i];
        auto min = std::numeric_limits<int>::max();
        auto index = -1;
        // 获取最小值
        for(auto j=i;j<len; j++){
           if(arr[j]<= min) {
               min = arr[j];
               index = j;
           }
        }

        // 交换最小值的位置
        arr[i] = min;
        arr[index] = temp;
    }
}

int main(int argc, char** argv){
    int* ori = new int[5]{3,2,5,1,4};

    print(ori, 5);
    cout << "------------" << endl;
    // bubbleSort(ori, 5);
    // insertionSort(ori, 5);
    // selectionSort(ori, 5);

    mergeSort(ori, 5);
    print(ori, 5);
    return 0;
}