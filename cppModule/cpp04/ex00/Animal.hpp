#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal{
protected:
	std::string type;
public:
	Animal();
	~Animal();
	Animal(std::string type);
	Animal(Animal const & a);
	Animal &operator=(Animal const & a);
	virtual void makeSound(void) const;
	std::string getType() const;
	void setType(std::string const type);
};

#endif