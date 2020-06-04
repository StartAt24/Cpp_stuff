#include <iostream>

using namespace std;

int binarySearch(int *arr, int l, int r, int target){
    if(l>r)
        return -1;

    //avoid stack over flow;
    auto mid =l+ (r-l)/2;

    if(arr[mid] == target)
        return mid;

    if(arr[mid] > target){
        int left = l;
        int right = mid-1;
        return binarySearch(arr, left, right, target);
    }else{
        int left = mid+1;
        int right = r;
        return binarySearch(arr, left, right, target);
    }
}

// 查找第一个等于某个值的元素
// 前提都是 数组是顺序的但有重复的元素
// [0,2,3,3,4,5,7,7,7,9,12,13]
int findFirstEqual(int *arr, int l, int r, int target){
    // 先二分查找一下。
    // 如果刚好在中间的话， 则试着从中间位置往前找，直到找到第一个。
    // 如果不在中间，大了或者小了的话，就在两边找， 找到了重复上述的操作。

    auto idx = binarySearch(arr, l, r, target);
    cout << idx << endl;
    // 当idx<0 的时候 因为undefined behavior 的存在，可能会导致最后结果小于0;
    while(arr[idx] == target && idx>=0){
        idx--;
    }
    return (idx+1);
}

int findFirstEqual2(int *arr, int l, int r, int target){
    if(l>r || !arr)
        return -1;

    while(l<=r) {
        int mid = l+ (r-l)/2;
        if(arr[mid] > target){
            r = mid-1;
        }else if(arr[mid] < target){
            l = mid+1; 
        }else{
            if(mid==0 || arr[mid-1] !=  target) 
                return mid;
            else 
                r = mid -1;
        }
    }

    return -1;
}


int findLastEqual(int *arr, int l, int r, int target){
    if(!arr || l>r)
        return -1;
    
    while(r>=l){
        int mid = l + (r-l)/2;
        if(arr[mid] >target){
            r = mid-1;
        }else if(arr[mid] < target){
            l = mid+1;
        }else{
            if(mid==r || arr[mid+1] != target)
                return mid;
            else
                l = mid +1; 
        }
    }
    return -1;
}


int findFirstGreater(int *arr, int l, int r, int target){
    if( !arr || l>r)
        return -1;

    while(l<=r) {
        auto mid = l + (r-l)/2;
        if(arr[mid] <= target) {
            l = mid+1;
        }else{
            if( mid==0 || arr[mid-1]<=target)
               return mid; 
            else 
                r=mid-1;
        }
    }
    return -1;
}


int findLastLess(int *arr, int l, int r, int target){
    if(!arr || l>r)
        return -1;

    while(l<=r){
        auto mid = l + (r-l)/2;
        if(arr[mid]>= target){
            r = mid-1;
        }else{
            if(arr[mid+1]>=target || mid==r)
                return mid;
            else
                l = mid+1;
        }
    }
    
    return -1;
}

int main(int argc, char** argv){
    int *chaos = new int[7]{1,3,4,8,11,33};
    // auto ret = binarySearch(chaos, 0, 6, 4);

    int *repeatChaos = new int[13]{0,0,2,3,3,3,4,5,7,8,10,10,12};
    // auto ret = findFirstEqual2(repeatChaos, 0, 12, 3);
    // auto ret = findLastEqual(repeatChaos, 0, 12, 12);
    // auto ret = findFirstGreater(repeatChaos, 0, 12, 3);
    auto ret = findLastLess(repeatChaos, 0, 12, 7);
    cout << ret << endl;
}