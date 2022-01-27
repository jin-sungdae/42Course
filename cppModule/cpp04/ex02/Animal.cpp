#include "Animal.hpp"

Animal::~Animal(){
	std::cout << "Destructor called" << std::endl;
}

std::string Animal::getType() const{
	return this->type;
}

