#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria{
protected:
	std::string type;
public:
	AMateria(std::string const & type);
	virtual ~AMateria() = 0;
	std::string const & getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter & target);
};

#endif
