//
// Created by 李思 on 2022/1/8.
//

/*
 *  相对复杂的问题 一般可以尝试两种思路 单调栈 或 优先队列
 *  对于单调栈 考虑两个方案 1.栈内存储值  2.栈内存储索引
 *  一般栈内存储值能解决的问题 用栈内存储索引也能解决
 */

#include "vector"
using namespace std;

int largestRectangleArea_old(vector<int> &height){
    if(height.empty()) return 0;

    height.push_back(0);
    vector<int> ret; // keep increase
    int maxArea = 0;
    for(int idx = 0; idx < height.size(); idx ++){
        if(ret.empty()) ret.push_back(idx);
        else{
            while(!ret.empty() && height[idx] < height[ret.back()]){
                int tmp = ret.back();
                ret.pop_back();
                if (ret.empty()) maxArea = max(height[tmp] * idx, maxArea) ; // 如果 height = [0] + height + [0] 此行代码可省略
                else {maxArea = max(height[tmp] * (idx - ret.back() - 1), maxArea);}
            }
            ret.push_back(idx);
        }
    }

    return maxArea;
}



int main(){
    vector<int> test{2,1,5,6,2,3};
    largestRectangleArea_old(test);
    return 1;
}

