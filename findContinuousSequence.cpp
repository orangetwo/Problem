//
// Created by 李思 on 2021/12/10.
//

#include "iostream"
#include "vector"
#include "queue"
using namespace std;

vector<vector<int>> findContinuousSequenceSum(vector<int> &nums, int target){

    queue<int> Q;
    int sum =0;
    vector<vector<int>> res;
    for(int & num : nums){

        sum += num;
        Q.push(num);

        while(sum > target){
            int deleteNum = Q.front();
            sum -= deleteNum;
            Q.pop();
        }

        if (sum == target){
            // TODO:
            vector<int> tmp;
            while(!Q.empty()){
                tmp.push_back(Q.front());
                Q.pop();
            }
            res.push_back(tmp);
            sum =0;
        }

    }
    return res;
}


int main() {

    vector<int> nums {9, 10, 11, 12, 13, 14, 15, 16, 18, 19, 20, 21, 22};
    findContinuousSequenceSum(nums, 100);
    return 0;
}

