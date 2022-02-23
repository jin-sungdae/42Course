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
	Animal(Animal const & a);
	virtual Animal &operator=(Animal const & a);
	virtual void makeSound(void) const;
	const std::string &getType() const;
	virtual Brain *getBrain() const = 0;

};

#endif