//
// Created by 李思 on 2021/12/10.
//
#include "iostream"
#include "vector"
#include "algorithm"
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


/*
 * example : 大于给定元素的最小元素
 * LeetCode 744
 * nextGreatestLetter
 */

int nextGreatestLetter(vector<int> &nums, int target){


    int left = 0, right = nums.size() - 1;

    if(target < nums[left]) return 1;
    if(target > nums[right]) return -1;
    while (left < right){
        int mid = left + (right - left) / 2;
        if (nums[mid] > target) right = mid;
        else if (nums[mid] <= target) left = mid + 1;
    }

    return left;
}

/*
 * 旋转数组的最小数字
 *
 */

int minNumberInRotateArray(vector<int> nums){

    if(nums.size() == 0) return 0;

    int left=0, right = nums.size() -1;

    if (nums[left] == nums[right] && nums[left + (right - left) / 2] == nums[right]){
        int res = *min_element(nums.begin(), nums.end());
        return res;
    }

    while(left < right){
        int mid = left + (right - left) / 2;
        if (nums[mid] <= nums[right]) right = mid;
        else left ++;
    }

    return nums[left];

}

int main() {
    cout << endl;
    // vector<int> nums{2, 3, 4, 5, 5, 5, 9, 10, 11, 14, 15};
    vector<int> nums{2, 3};
    int target = 2;
    int idx = nextGreatestLetter(nums, target);
    cout << idx << endl;

    vector<int> test{3, 3, 1, 3};
    minNumberInRotateArray(test);
    return 0;
}

