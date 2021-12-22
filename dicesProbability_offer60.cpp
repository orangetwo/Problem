//
// Created by 李思 on 2021/12/19.
//

#include "vector"
#include "math.h"
using namespace std;

class Solution {
public:
    vector<double> dicesProbability(int n) {
        int dp[15][70];

        memset(dp, 0, sizeof(dp));

        for(int i=0; i <= 6; i++) {dp[1][i] = 1;}

        for(int i = 2; i <= n; i ++){ // 代表骰子的数量
            for(int j = i; j <= 6*i; j ++){ // 代表的投掷点数
                for(int cur = 1; cur <= 6; cur ++){
                    if(j - cur <= 0) {break;}
                    dp[i][j] += dp[i-1][j-cur];
                }
            }
        }

        int all = pow(6, n);
        vector<double> ret;

        for(int i=n; i <= 6*n; i ++){
            ret.push_back(dp[n][i] * 1.0 / all);
        }

        return ret;
    }
};