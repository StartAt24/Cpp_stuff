#include <iostream>

using namespace std;

int binarySearch(int *arr, int l, int r, int target){
    if(l>r)
        return -1;

    auto mid = (l+r)/2;

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

int main(int argc, char** argv){
    int *chaos = new int[7]{1,3,4,8,11,33};
    auto ret = binarySearch(chaos, 0, 6, 4);
    cout << ret << endl;
}