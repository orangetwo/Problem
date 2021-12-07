#include <iostream>
#include "string"
int main() {
    //std::cout << "Hello, World!" << std::endl;

    char alls[] = "abcdefgh";
    std::string one (alls, 30);
    std::cout << one <<" "<<one.size()<<std::endl;
    return 0;
}
