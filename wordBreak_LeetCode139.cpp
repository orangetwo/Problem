//
// Created by 李思 on 2022/1/8.
//

#include "vector"
#include "string"
#include "set"
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    set<string> map(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;

    for(string::size_type i = 1; i <= s.size(); i ++){
        for(auto j = 0; j < i; j ++){
            if(dp[j] && map.count(s.substr(j,i-j)) > 0)
            {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[s.size()];
}

int main(){

    string s = "applepenapple";
    vector<string> wordDict{"apple","pen"};
    wordBreak(s, wordDict);

    return 1;

}