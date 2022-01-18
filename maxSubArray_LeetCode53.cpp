//
// Created by 李思 on 2022/1/18.
//

/*
 * case :
 *      nums = [-2,1,-3,4,-1,2,1,-5,4]
 *      输出：6
 */

#include "vector"
using namespace std;

int maxSubArray(vector<int> &nums){

    int maxValue = nums[0];
    int dp = 0;
    for(auto x : nums){
        dp = max(x,dp + x);
        maxValue = max(maxValue, dp);
    }
    return maxValue;
}

int main(){
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    maxSubArray(nums);
}
