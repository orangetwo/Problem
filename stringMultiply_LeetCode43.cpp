//
// Created by 李思 on 2022/1/7.
//

#include "string"
#include "vector"


using namespace std;

string Multiply(string num1, char &num2) {
    int borrow = 0;
    int b = num2 - '0';
    string ret = "";

    for(int i = num1.size() -1 ; i >=0; i--){
        int tmp = num1[i] - '0';
        ret = to_string((tmp * b + borrow) % 10) + ret;
        borrow = (tmp * b + borrow) / 10;
    }
    if(borrow > 0) ret = to_string(borrow) + ret;

    //TODO: clean zero
    return ret;
}


string stringMultiply(string num1, string num2){
    vector<string> candi;
    int count = 0;
    for(int i = num2.size() - 1; i >= 0; i --){
        string ret = Multiply(num1, num2.at(i));
        string zeros = string(count, '0');

        candi.push_back(ret+zeros);
        count ++;
    }

    return "";
}


int main(){

    string num1 = "9870";
    string num2 = "4444";
    stringMultiply(num1, num2);

    return 1;

}