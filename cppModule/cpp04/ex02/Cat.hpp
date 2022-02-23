#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal{
public:
	Cat();
	~Cat();
	Cat(Cat const & c);
	Cat & operator=(Cat const & c);
	virtual Animal & operator=(Animal const & a);
	virtual void makeSound() const;
	virtual Brain *getBrain() const;

private:
	Brain *brain;
};

#endif