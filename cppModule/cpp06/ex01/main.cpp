#include <iostream>
#include <stdint.h>
#include "Data.hpp"

uintptr_t serialize(Data* ptr){
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw){
     return reinterpret_cast<Data *>(raw);
}

int main(){
	Data		*ptr = new Data;
    Data		*newPtr;
    uintptr_t	raw;
    
    ptr->data = "hello world 13!@#";
    raw = serialize(ptr);
    std::cout << raw << std::endl;
    newPtr = deserialize(raw);
    std::cout << "newPtr->data = " << newPtr->data << std::endl;
}