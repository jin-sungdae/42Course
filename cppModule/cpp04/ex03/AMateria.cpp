#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : type(type){
	std::cout << "type one constructor called" << std::endl;
}

std::string const &AMateria::getType() const{
	return this->type;
}

