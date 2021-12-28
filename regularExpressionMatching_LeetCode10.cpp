//
// Created by Orange on 2021/12/28.
//

#include "string"
using namespace std;

class Solution{
public:
    bool isMatching(string s, string p){
        int m = s.size();
        int n = p.size();

        bool dp[m+1][n+1];
        dp[0][0] = true;

        for (int j = 1; j <= n; j ++){
            // if p[0] == '*' then invalid
            // 保证每次出现字符 * 时，前面都匹配到有效的字符
            if(p[j-1] == '*') dp[0][j] = dp[0][j-2];
        }

        for (int i = 1; i <= m; i ++){
            for(int j = 1; j <= n; j++){
                if (s[i-1] == p[j-1] || p[j-1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if ( p[j-1] == '*'){
                    if (p[i-2] == '.'){ // 0次 1次 N次
                        dp[i][j] = dp[i-1][j] || dp[i][j-2] || dp[i][j-1];
                    }
                    else if (p[i-2] == s[i-1]){ // 0次 1次 N次
                        dp[i][j] = dp[i-1][j] || dp[i][j-2] || dp[i][j-1];
                    } else{
                        dp[i][j] = dp[i][j-2];
                    }

                }
            }

        }

        return dp[m][n];
    }
};

