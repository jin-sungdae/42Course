#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    type = "wrongAnimal";
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal destructor called" << std::endl;
}
std::string WrongAnimal::getType() const{
    return type;
}
void WrongAnimal::setType(std::string const type){
    this->type = type;
}
void WrongAnimal::makeSound() const{
    std::cout << "WrongAnimal make sound" << std::endl;
}