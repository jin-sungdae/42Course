#include "C.hpp"

C::C(){
    std::cout << "C default constructor called" << std::endl;
}

C::~C(){
    std::cout << "C destuctor called" << std::endl;
}
    
C::C(C const & c){
    *this = c;
    std::cout << "C a little Copy" << std::endl;
}
    
C& C::operator=(C const & c){
    (void)c;
    std::cout << "C deep Copy" << std::endl;
    return *this;
}
