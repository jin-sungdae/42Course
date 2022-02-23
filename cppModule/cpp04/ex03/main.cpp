
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(){

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << "\n";

	ICharacter* jin = new Character("jin");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	jin->equip(tmp);
	tmp = src->createMateria("cure");
	jin->equip(tmp);
	tmp = src->createMateria("ice");
	jin->equip(tmp);
	tmp = src->createMateria("cure");
	jin->equip(tmp);
	std::cout << "\n";

	ICharacter* monster = new Character("monster");
	jin->use(3, *monster);
	jin->use(2, *monster);
	jin->use(1, *monster);
	jin->use(0, *monster);

	delete monster;
	delete jin;
	delete src;
	return 0;
}