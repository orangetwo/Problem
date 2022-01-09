//
// Created by 李思 on 2022/1/8.
//

/*
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 */

#include "string"
#include "unordered_map"
#include "vector"
#include "deque"
#include "set"

using namespace std;

string minWindow(string s, string t){
    unordered_map<char, int> need, window;

    for(char & i : t) need[i] ++;

    int left = 0;
    int vaild = 0;
    int length = INT_MAX;

    int start =0;
    for(int i = 0; i < s.size(); i++){

        char c = s[i];

        if(need.count(c) == 1){
            window[c] ++;
            if(window[c] == need[c]) vaild ++;
        }

        while(vaild == need.size()){
            // record current length and substr
            //TODO:
            if(i + 1 - left < length){
                start = left;
                length = i + 1 - left;
            }

            char d = s[left];
            left ++;
            if(need.count(d)){
                if (window[d] == need[d]) vaild --;
                window[d] --;
            }

        }


    }

    return length == INT_MAX ? "" : s.substr(start, length);
}

int main(){
    string s = "a";
    string t = "aa";
    string ret = minWindow(s, t);

    return 1;
}