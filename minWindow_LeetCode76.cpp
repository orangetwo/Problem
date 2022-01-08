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
    unordered_map<char, int> map;
    set<char> dict;

    for(char & i : t){
        dict.insert(i);
    }

    int left = 0;

    for(int i = 0; i < s.size(); i++){
        if(dict.count(s.at(i)) == 0 && map.empty()) left ++;
        else if ()
    }
}

int main(){
    unordered_map<char, int> map;
    set<char> dict;
    string t = "123";
    for(string::size_type i = 0; i < t.size() ; i++){
        map[t.at(i)]= 1;
    }
    for(string::size_type i = 0; i < t.size() ; i++) dict.insert(t.at(i));

    char x = 'o';

    auto y = map[x];

    return 1;
}