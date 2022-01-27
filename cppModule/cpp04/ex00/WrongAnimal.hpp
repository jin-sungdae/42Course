#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal{
protected:
	std::string type;
public:
	WrongAnimal();
	~WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(WrongAnimal const & wa);
	WrongAnimal & operator=(WrongAnimal const & wa);
	virtual void makeSound() const;
	std::string getType() const;
	void setType(std::string const type);

};

#endif