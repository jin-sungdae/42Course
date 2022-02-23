#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(MateriaSource const & m);
	MateriaSource &operator=(MateriaSource const & m);
	virtual void learnMateria(AMateria* amtareia);
	virtual AMateria* createMateria(std::string const & type);
	
private:
	AMateria *amteria[4];
	int learnNumber;
};

#endif