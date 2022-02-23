#include "Ice.hpp"

Ice::Ice() : AMateria("ice"){
    std::cout << "Ice default constructor called" << std::endl;
}

Ice::~Ice(){
    std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(Ice const & i): AMateria("ice"){
    std::cout << "Ice a little Copy called" << std::endl;
    *this = i;
}

Ice &Ice::operator=(Ice const & i){
    this->type = i.type;
    std::cout << "Ice deep Copy called" << std::endl;
    return *this;
}

AMateria *Ice::clone() const{
    return (new Ice(*this));
}

void Ice::use(ICharacter & target){
    std::cout << "ice shoot ---->" << target.getName() << std::endl;
}