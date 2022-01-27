#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"


class Dog : public Animal{
public:
	Dog();
	~Dog();
	Dog(Dog const &d);
	Dog & operator=(Dog const & d);
	virtual Animal & operator=(Animal const & d);
	virtual void makeSound() const;
	Brain *getBrain() const;

private:
	Brain *brain;
};

#endif