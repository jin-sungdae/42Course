#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	this->learnNumber = 0;
	for (int i = 0; i < 4; i++){
		this->amteria[i] = NULL;
	}
	std::cout << "MateriaSource Constructor called" << std::endl;
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < 4; i++){
		if (this->amteria[i])
			delete this->amteria[i];
	}
	std::cout << "MateriaSource Destructor called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &m){
	std::cout << "MateriaSource a little Copy Called" << std::endl;
	*this = m;
}

MateriaSource &MateriaSource::operator=(MateriaSource const & m){
	for (int i = 0; i < 4; i++){
		if (this->amteria[i])
			delete this->amteria[i];
		if (m.amteria[i])
			this->amteria[i] = m.amteria[i];
		else
			this->amteria[i] = NULL;
	}
	std::cout << "MateriaSource Deep Copy Called" << std::endl;
	return *this;
}

void MateriaSource::learnMateria(AMateria* ma){
	if (this->learnNumber>= 4)
		std::cout << "Can't learn materia" << std::endl;
	else{
		this->amteria[this->learnNumber] = ma;
		this->learnNumber++;
		std::cout << "Learn Materia" << std::endl;
	}
}

AMateria * MateriaSource::createMateria(std::string const & type){
	int i = 0;

	while (i < 4 && this->amteria[i]){
		if (type == this->amteria[i]->getType())
			return this->amteria[i]->clone();
		i++;
	}
	return NULL;

}