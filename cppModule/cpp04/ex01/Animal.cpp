#include "Animal.hpp"

Animal::Animal(){
	std::cout << "Animal constructor called" << std::endl;
	type = "Animal";
}

Animal::~Animal(){
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(Animal const & a){
	*this = a;
	std::cout << "Animal a little Copy called" << std::endl;
}

Animal & Animal::operator=(Animal const & a){
	std::cout << "Animal Deep Copy called" << std::endl;
	this->type = a.getType();
	return (*this);
}

void Animal::makeSound() const{
	std::cout << "Animal make Sound" << std::endl;
}

const std::string &Animal::getType() const{
	return (this->type);
}



