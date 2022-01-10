//
// Created by 李思 on 2022/1/10.
//

#include "string"
#include "unordered_map"
using namespace std;

int lengthOfLongestSubstring(string s){
    unordered_map<char, int> map;

    int left = 0;
    int ret = 0;
    for(int idx = 0; idx < s.size(); idx ++){
        char c = s[idx];
        map[c] ++;

        while(map[c] > 1){
            char d = s[left];
            left ++;
            map[d] --;
        }
        ret = max(ret, idx + 1 - left);
    }
    return ret;
}
