//
// Created by Orange on 2021/12/11.
//

#include "iostream"
#include "vector"
using namespace std;

int moreThanHalfNum(vector<int> nums){

    int count = 0;
    int cur = -1;

    for(auto num: nums){
        if(count == 0) {
            cur = num;
            count ++;
        } else if(cur == num) {
            count ++;
        } else if(cur != num){
            count --;
        }
    }

    return cur;

}

int main() {
    cout<<endl;
    return 0;
}
