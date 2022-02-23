#include "Cure.hpp"

Cure::Cure() : AMateria("cure"){
    std::cout << "Cure default Constructor called" << std::endl;
}

Cure::~Cure(){
    std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(Cure const & c) : AMateria("cure"){
    std::cout << "Cure a little Copy Called" << std::endl;
    *this = c;
}

Cure & Cure::operator=(Cure const & c){
    std::cout << "Cure deep Copy called" << std::endl;
    this->type = c.type;
    return *this;
}

AMateria *Cure::clone() const{
    return (new Cure(*this));
}

void Cure::use(ICharacter & target){
    std::cout << target.getName() << "heals" << std::endl;
}