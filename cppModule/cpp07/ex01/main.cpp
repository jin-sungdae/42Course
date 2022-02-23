#include "iter.hpp"
#include <iostream>

template<typename T>
void fcCalledArr(T &arr){
    std::cout << arr << std::endl;
}

int main(){
    std::string arr[3];
    int intArry[3];

    intArry[0] = 1;
    intArry[1] = 2;
    intArry[2] = 3;
    arr[0] = "hello cpp";
    arr[1] = "hello c";
    arr[2] = "hello java";
    ::iter(arr, 3, &fcCalledArr);
    ::iter(intArry, 3, &fcCalledArr);
}