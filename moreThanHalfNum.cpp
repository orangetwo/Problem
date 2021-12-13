//
// Created by 李思 on 2021/12/11.
//

#include "iostream"
#include "vector"
using namespace std;

int moreThanHalfNum(vector<int> &nums){
    int count = 0;
    int cur = 0;

    for(auto num: nums){
        if(count == 0){
            cur = num;
            count ++;
        } else if (num == cur){
            count ++;
        } else if (num != cur){
            count --;
        }
    }

    return cur;
}

int main() {
    cout << endl;
    // vector<int> nums{1,2,3,2,2,2,5,4,2};
    // vector<int> nums{3,3,3,3,2,2,2};
    vector<int> nums{3};
    int result = moreThanHalfNum(nums);
    return 0;
}
