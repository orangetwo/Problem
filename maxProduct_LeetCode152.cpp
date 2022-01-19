//
// Created by 李思 on 2022/1/19.
//
#include "vector"
#include "iostream"
using namespace std;

int maxProduct(vector<int>& nums) {

    int dpMax = nums[0];
    int dpMin = nums[0];
    int ret = nums[0];

    for(int i = 1; i < nums.size(); i++){
        int dpMaxTmp = dpMax;
        int dpMinTmp = dpMin;
        dpMax = max(max(dpMaxTmp * nums[i], dpMinTmp * nums[i]), nums[i]);
        dpMin = min(min(dpMaxTmp * nums[i], dpMinTmp * nums[i]), nums[i]);
        cout << dpMax << ' ' << dpMin << endl;
        ret = max(ret, dpMax);
    }
    cout << ret;
    return ret;
}

int main(){
    vector<int> nums{-2,3,-4};
    maxProduct(nums);
}
