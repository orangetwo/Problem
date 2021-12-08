//
// Created by 李思 on 2021/12/8.
//

/*
 *  第一个只出现一次的字符位置
 */


#include "iostream"
#include "string"

int firstNotRepeatingChar(std::string strX){
    // 创建 长度为128的数组, 其中每个元素为0
    int *cnts = new int [128]();

    for(auto &x: strX){
        cnts[int(x)] += 1;
    }

    for(int i =0; i < strX.length(); i++){
        if(cnts[int(strX[i])] == 1) return i;
    }


    delete [] cnts;

    return -1;

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    // std::cout << int('9') << std::endl;

    std::cout << firstNotRepeatingChar("azkkbacc") << std::endl;
    return 0;
}