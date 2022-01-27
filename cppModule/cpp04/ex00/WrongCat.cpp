#include "WrongCat.hpp"

WrongCat::WrongCat(){
	this->type = "Wrong Cat";
	std::cout << "Wrong Cat constructor called" << std::endl;
}

WrongCat::~WrongCat(){
	std::cout << "Wrong Cat destructor called" << std::endl;
}

void WrongCat::makeSound() const{
	std::cout << "Wrongcat make sound" << std::endl;
}