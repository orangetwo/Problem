//
// Created by 李思 on 2021/12/10.
//
#include "iostream"
#include "vector"
using namespace std;

// binary search framework

int binarySearch(vector<int> nums, int target){

    int left =0, right = nums.size() -1;

    while(left <= right){
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;

        else if (nums[mid] > target) right = mid - 1;
        else if (nums[mid] < target) left = mid + 1;
    }

    return -1;

}

/*
 * 我的理解是 当你对 right/left 调整的时候不为 mid +/- 1时, 比如 调整为 mid时, 考虑 left < right
 */










int main() {
    cout << endl;
    return 0;
}

