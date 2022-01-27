#include "Dog.hpp"

Dog::Dog(){
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog(){
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const{
	std::cout << "Dog make Sound" << std::endl;
}

Dog::Dog(Dog const & d){
	*this = d;
	std::cout << "Dog a little Copy" << std::endl;
}

Dog & Dog::operator=(Dog const & d){
	this->type = d.getType();
	*(this->brain) = *(d.getBrain());
	std::cout << "Dog deep Copy" << std::endl;
	return *this;
}

Animal & Dog::operator=(Animal const & d){
	this->type = d.getType();
	*(this->brain) = *(d.getBrain());
	std::cout << "UpCasting Dog deep Copy" <<std::endl;
	return *this;
}

Brain *Dog::getBrain() const{
	return this->brain;
}

