//
// Created by 李思 on 2021/12/15.
//

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result{-1, -1};
        if(nums.empty()) return result;

        if (nums[0] > target) return result;
        if (nums[nums.size()-1] < target) return result;

        int leftMin = 0;
        int rightMin = nums.size() -1;

        // find the first element that equals to target
        while(leftMin < rightMin){
            int midMin = leftMin + (rightMin - leftMin) / 2;
            if (nums[midMin] == target) rightMin = midMin;
            else if (nums[midMin] < target) leftMin = midMin + 1;
            else rightMin = midMin - 1;
        }
        if(nums[leftMin] == target) result[0] =leftMin;
        else return result;

        target = target + 1;

        int leftMax = 0;
        int rightMax = nums.size() -1;

        // find the first element that equals to target + 1
        while(leftMax < rightMax){
            int midMax = leftMax + (rightMax - leftMax) / 2;
            if (nums[midMax] == target) rightMax = midMax;
            else if (nums[midMax] < target) leftMax = midMax + 1;
            else rightMax = midMax - 1;
        }

        if(nums[leftMax] == target - 1) result[1] =leftMax;
        else result[1] = leftMax -1;

        return result;

    }
};