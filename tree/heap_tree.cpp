#include <iostream>
#include <functional>
using namespace std;

void swap(int* arr, int l, int r){
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
}


// store in an array.
// left_child = 
class HeapTree{
public:
    HeapTree(int cap):_count(0),_cap(cap){
        // +1是为了 将root 存放在，1号位置，这样方便用到 i*2和 i*2+1 来查找子节点
        _arr = new int[cap+1];
    };
    ~HeapTree();

    int insert(int n){
        if(_count >= _cap){
            cout << "insert failed" <<endl;
            return -1;
        }
        _count++;
        _arr[_count] = n;

        // heapify
        int i = _count;
        while(i/2>0 && _arr[i]>_arr[i/2]){
            swap(_arr, i, i/2);
            i = i/2;
        }
    };

    int removeMax(int n){
        if(_count == 0)
            return  -1;
        // 将最后一个元素 替换到第一个元素
        _arr[1] = _arr[_count];
        --_count;

        [](int*arr, int n, int i){
            while(1){
                int maxPos = i;
                if(i*2 <= n && arr[i]<arr[i*2]) maxPos = i*2;
                if(i*2+1 <= n && arr[i]<arr[i*2+1]) maxPos = i*2+1;
                if(maxPos == i)
                    break;
                swap(arr, i, maxPos);
                i = maxPos;
            }
        }(_arr, _count, 1);
    }
private:
    int* _arr;
    int  _count;
    int  _cap;
};

int main(int argc, char** argv){
    HeapTree h(30);
    h.insert(1);
    h.insert(2);
    h.insert(3);
    return 0;
}