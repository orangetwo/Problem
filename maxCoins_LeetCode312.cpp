//
// Created by 李思 on 2022/1/12.
//

#include "vector"
using namespace std;

int maxCoins(vector<int> &nums){

    int n = nums.size();

    vector<int> points(2 + nums.size(), 0);
    points[0] = 1;
    points[nums.size() + 1] = 1;

    for(int i = 0; i < nums.size(); i++){
        points[i+1] = nums[i];
    }

    vector<vector<int>> dp(nums.size() + 2, vector<int>(nums.size() + 2, 0));

    for(int len = 0; len <= n; len++){
        for(int i = 1; i + len -1 < n; i ++) {
            int j = i + len;
            for(int k = i; k <= j; k++){
                dp[i][j] = max(dp[i][j], dp[i][k-1] + points[i-1] * points[k] * points[j+1] + dp[k+1][j]);
            }
        }

    }

    return dp[1][n];

}