#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type){
	this->type = type;
	std::cout << "WrongAnimal onetype constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & wa){
	*this = wa;
	std::cout << "WrongAnimal a little copy called" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & wa){
	this->type = wa.getType();
	std::cout << "WrongAnimal Deep copy called" << std::endl;
	return *this;
}

std::string WrongAnimal::getType() const{
	return this->type;
}

void WrongAnimal::setType(std::string const type){
	this->type = type;
}

void WrongAnimal::makeSound() const{
	std::cout << "WrongAnimal make sound" << std::endl;
}