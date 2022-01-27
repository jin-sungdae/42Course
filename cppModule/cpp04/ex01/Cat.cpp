#include "Cat.hpp"

Cat::Cat(){
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat(){
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const{
	std::cout << "Cat make Sound" << std::endl;
}

Cat::Cat(Cat const & c){
	*this = c;
	std::cout << "Cat a little Copy called" << std::endl;
}

Cat & Cat::operator=(Cat const & c){
	
	this->type = c.getType();
	*(this->brain) = *(c.getBrain());
	std::cout << "Cat deep Copy called" << std::endl;
	return *this;
}
Animal & Cat::operator=(Animal const & a){
	this->type = a.getType();
	*(this->brain) = *(a.getBrain());
	std::cout << "Cat UpCasting deep Copy called" << std::endl;
	return *this;
}
Brain *Cat::getBrain() const{
	return this->brain;
}

