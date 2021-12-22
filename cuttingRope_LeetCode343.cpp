//
// Created by 李思 on 2021/12/22.
//

#include "vector"
using namespace std;

/*
 * dp[i]表示长度为i的绳子至少切割一次的情况下 乘积的最大值
 *
 */

class Solution{
public:
    int cuttingRope(int n){

        vector<int> dp(n+1, 0);
        dp[1] = 1;

        for(int i = 2; i <= n; i ++ ){
            for(int j = 1; j < i; j++){
                dp[i] = max(dp[i], max(dp[j]*(i-j), j*(i-j)));
            }

        }

        return dp[n+1];
    }
};

int main(){
    int n = 2;
    Solution s;
    s.cuttingRope(n);
}