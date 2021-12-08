//
// Created by 李思 on 2021/12/8.
//

#include "iostream"
#include "queue"
#include "vector"
using namespace std;

vector<int> getKLeastNum(vector<int> &nums, int k){
    vector<int> result(k, 0);
    if (k == 0) return result ;
    priority_queue<int> maxHeap;
    vector<int>::size_type i = 0;
    for(; i < k; i++){
        maxHeap.push(nums[i]);
    }

    for(;i < nums.size(); i++){
        if (maxHeap.top() > nums[i]) {
            maxHeap.pop();
            maxHeap.push(nums[i]);
        }
    }

    for(int j = 0; j < k; j++){
        result[j] = maxHeap.top();
        maxHeap.pop();
    }

    return result;

}

int main(){

    // priority_queue<int, vector<int>, less<int> > maxvalue 大顶堆
    // priority_queue<int, vector<int>, greater<int> > minvalue 小顶堆
    priority_queue<int> maxHeap; //默认大顶堆


    return 1;
}