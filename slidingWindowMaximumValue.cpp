//
// Created by 李思 on 2021/12/9.
//

#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
#include "deque"
using namespace std;


vector<int> getSlidingWindowMaxValue(vector<int> &nums, int &window){

    vector<int> result;
    if (nums.size() <= 2) {
        result.push_back(*max_element(nums.begin(), nums.end()));
    }

    deque<int> q;
    for(vector<int>::size_type i = 0; i < nums.size(); i++){

        while(!q.empty() && nums[q.back()] <= nums[i]){
            q.pop_back();
        }

        q.push_back(i);

        if(i - q.front() > window -1) {
            q.pop_front();
        }

        if(i + 1 >= window) {
            result.push_back(nums[q.front()]);
        }
    }

    return result;

}


int main() {
    // std::cout << int('9') << std::endl;
    vector<int> nums {2, 3, 4, 2, 6, 2, 5, 7};
    int window = 3;


    vector<int> res = getSlidingWindowMaxValue(nums, window);
    for(auto num : res){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
