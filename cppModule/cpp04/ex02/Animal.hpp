#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal{
protected:
	std::string type;
public:
	virtual ~Animal();
	virtual Animal &operator=(Animal const & a) = 0;
	virtual void makeSound() const = 0;
	std::string getType() const;
	virtual Brain *getBrain() const = 0;

};

#endif