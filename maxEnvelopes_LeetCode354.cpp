//
// Created by 李思 on 2022/1/10.
//

#include "vector"
using namespace std;
class Solution {
public:
    static bool cmp(vector<int> &x, vector<int> &y) {
        return x[0] == y[0] ? x[1] >= y[1] : x[0] <= y[0];
    };

    int maxEnvelopes(vector<vector<int>> &envelopes) {
        vector<int> dp(envelopes.size(), 1);

        sort(envelopes.begin(), envelopes.end(), cmp);

        for (int i = 1; i < envelopes.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (envelopes[i][1] > envelopes[j][1]) dp[i] = max(dp[j] + 1, dp[i]);
            }
        }

        int ret = 0;
        for (auto &x: dp) {
            ret = max(ret, x);
        }
        return ret;
    };
};


int main(){
    vector<vector<int>> envelopes = {{4,5},{4,6},{6,7},{2,3},{1,1}};//{{5,4},{6,4},{6,7},{2,3}};
    Solution s;
    s.maxEnvelopes(envelopes);
}