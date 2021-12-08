//
// Created by 李思 on 2021/12/7.
//

#include "iostream"
#include "vector"
using namespace std;


int findRepeatNumber(vector<int>& nums){

    int i;
    for(i=0; i < nums.size(); i++){

        while(nums[i] != i){
            if (nums[i] == nums[nums[i]]) return nums[i];
            swap(nums[i], nums[nums[i]]);
        }
    }
    return -1;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}