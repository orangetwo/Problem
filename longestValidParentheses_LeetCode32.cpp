//
// Created by 李思 on 2022/1/17.
//

#include "string"
#include "vector"
using namespace std;

int longestValidParentheses(string s) {

    vector<int> stack;
    int start = 0;
    int end = 0;
    int ret = 0;

    for(int i = 0; i < s.length(); i ++){
        if(s[i] == '('){
            stack.push_back(i);
        }
        else{
            if(!stack.empty()){
                stack.pop_back();
                if(stack.empty()) ret = max(ret, i - start + 1);
                else ret = max(ret, i - stack.back());
            }
            else{
                start = i + 1;
            }
        }

    }
    return ret;

}