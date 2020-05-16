#include <iostream>

using namespace std;

void print(int* arr, int len){
    for(auto i=0;i<len;i++){
        cout << "index: "<<i << ",value: "<< arr[i] << endl;
    }
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
void insertSort(int *&arr, int len){
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
        arr[index] = val;
    }
}

int main(int argc, char** argv){
    int* ori = new int[5]{3,2,5,1,4};
    bubbleSort(ori, 5);
    print(ori, 5);
    return 0;
}