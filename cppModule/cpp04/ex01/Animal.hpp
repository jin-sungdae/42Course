#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal{
protected:
	std::string type;
public:
	Animal();
	virtual ~Animal();
	Animal(std::string type);
	Animal(Animal const & a);
	virtual Animal &operator=(Animal const & a);
	virtual void makeSound(void) const;
	std::string getType() const;
	void setType(std::string const type);
	virtual Brain *getBrain() const = 0;

};

#endif