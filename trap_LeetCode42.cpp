//
// Created by 李思 on 2021/12/17.
//

#include "vector"
#include "stack"
using namespace std;

// [0,1,0,2,1,0,1,3,2,1,2,1]

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2) return 0;

        int left = 0, right = height.size() - 1;
        int l_max = height[0], r_max = height[height.size() - 1];

        int ret = 0;

        while(left < right){
            l_max = max(l_max, height[left]);
            r_max = max(r_max, height[right]);

            if(l_max >= r_max){
                ret += (r_max - height[right]);
                right --;
            }
            else{
                ret += (l_max - height[left]);
                left ++;
            }
        }
        return ret;
    }

    int trapMonotonicStack(vector<int> &height){

        stack<int> monoStack{};
        int sum = 0;

        for(auto i = 0; i < height.size(); i++){

            while (!monoStack.empty() && height[monoStack.top()] < height[i]){
                int top = monoStack.top();
                monoStack.pop();

                if(monoStack.empty()) break;

                int distance = i - monoStack.top();
                int minValue = min(height[monoStack.top()], height[i]);
                sum += distance*(minValue - height[top] - 1);

            }
            monoStack.push(i);

        }


        return sum;
    }
};