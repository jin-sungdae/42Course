#include "B.hpp"

B::B(){
    std::cout << "B default Constructor Called" << std::endl;
}

B::~B(){
    std::cout << "B destructor called" << std::endl;
}

B::B(B const & b){
    *this = b;
    std::cout << "B a little Copy" << std::endl;
}

B& B::operator=(B const & b){
    (void) b;
    std::cout << "B Deep Copy" << std::endl;
    return *this;
}
