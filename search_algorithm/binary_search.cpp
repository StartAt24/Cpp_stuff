#include <iostream>

using namespace std;

int binarySearch(int *arr, int l, int r, int target){
    if(l>r)
        return -1;

    if(r-l == 1){
        if(arr[l] == target)
            return l;
        if(arr[r] == target)
            return r;
    }

    auto mid = (l+r)/2;
    if(arr[mid] == target)
        return mid;

    if(arr[mid] > target){
        int left = l;
        int right = mid;
        return binarySearch(arr, left, right, target);
    }else{
        int left = mid;
        int right = r;
        return binarySearch(arr, left, right, target);
    }

}

int main(int argc, char** argv){
    int *chaos = new int[7]{1,3,4,8,11,33};
    auto ret = binarySearch(chaos, 0, 6, 1);
    cout << ret << endl;
}