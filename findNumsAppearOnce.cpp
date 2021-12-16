//
// Created by 李思 on 2021/12/16.
//

#include "iostream"
#include "vector"
using namespace std;

class solution{
public:
    int findNumsAppearOnce(vector<int> &nums){
        int ret = 0;
        for(auto num : nums){
            ret ^= num;
        }

        return ret;
    }
};

int main(){
    vector<int> nums{2,2,1,4, 4};
    solution s;
    cout << s.findNumsAppearOnce(nums) << endl;
}