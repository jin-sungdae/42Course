#include "A.hpp"

A::A(){
    std::cout << "A default constructor called" << std::endl;
}

A::~A(){
    std::cout << "A destructor called" << std::endl;
}

A::A(A const & a){
    *this = a;
    std::cout << "A a little copy" << std::endl;
}

A & A::operator=(A const & a){
    (void)a;
    std::cout << "A deep Copy" << std::endl;
    return *this;
}
