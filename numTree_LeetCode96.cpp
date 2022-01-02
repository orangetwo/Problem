//
// Created by 李思 on 2022/1/2.
//

#include "vector"
using namespace std;

class Solution{
public:
    int numTrees(int n){
        if(n <= 0) return 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        return numTrees(1, n, dp);
    }

    int numTrees(int begin, int end, vector<vector<int>> &dp){
        if(begin > end) return 1;

        if (dp[begin][end] != 0) return dp[begin][end];

        int ret = 0;
        for(int i = begin; i<= end; i++){

            int left = numTrees(begin, i-1, dp);
            int right = numTrees(i+1, end, dp);

            ret += left * right;
        }
        dp[begin][end] = ret;
        return ret;
    }

};


int main(){
    Solution s;
    int kill = s.numTrees(3);

    return kill;
}