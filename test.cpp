//
// Created by Orange on 2021/12/28.
//


#include "iostream"
using namespace std;

void modifyValue(int x){
    // 这里我们想修改x的值
    x = 0;
}

void modifyValue(int *x){
    *x = 0;
}

int main(){

    int x = 1;

    modifyValue(x);
    cout << x << endl;
    modifyValue(&x);
    cout << x << endl;

    return 1;
}