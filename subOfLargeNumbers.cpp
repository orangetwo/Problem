//
// Created by 李思 on 2021/12/5.
// 大数相减(字符串减法)
//

#include <iostream>
#include "algorithm"
using namespace std;


bool isGreater(string minuend, string subtrahend){
    if (minuend.size() == subtrahend.size()) return minuend >= subtrahend;
    else return minuend.size() > subtrahend.size();
}


string Sub(string minuend, string subtrahend){

    string sign = "";

    if(!isGreater(minuend, subtrahend)){
        sign = "-";
        string tmp;
        tmp = minuend;
        minuend = subtrahend;
        subtrahend = tmp;
    }

    string numOfZeros (minuend.size()-subtrahend.size(), '0');

    subtrahend = numOfZeros + subtrahend;
    cout << subtrahend << " " << subtrahend.size() <<endl;

    int borrow = 0;
    string result;

    for(string::size_type i = minuend.size() ; i >0 ; i--){

        int a = minuend[i-1] - '0';
        int b = subtrahend[i-1] - '0';

        int z = (a - b - borrow + 10) % 10;
        result += ('0' + z) ;
        borrow = a - b - borrow < 0 ? 1:0;

    }
    cout << result <<endl;
    reverse(result.begin(), result.end());
    cout << result <<endl;

    string::size_type pos;
    // 之所以 result.size() - 1 是保留最后一位, 即 "0000" -> "0"
    for(pos = 0; pos < result.size() - 1; pos++){
        if(result[pos] != '0') break;
    }

    return sign + result.substr(pos);
}


int main() {
    string minuend = "12345";
    string subtrahedn = "12345";
    bool indicate = isGreater(minuend, subtrahedn);
    cout << !indicate << endl;

    string res = Sub(minuend, subtrahedn);
    cout << res;

    return 1;
}
