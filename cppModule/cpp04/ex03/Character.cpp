#include "Character.hpp"

Character::Character(): name(""), haveInventorysize(0){
	
	for (int i = 0; i < 4; i++){
		this->inventory[i] = NULL;
	}
	std::cout << "Character constructor called" << std::endl;
}

Character::Character(std::string const &name){
	*this = Character();
	this->name = name;
	std::cout << "one Name constructor called" << std::endl;
}

Character::~Character(){
	std::cout << "Character destructor called" << std::endl;
}

Character::Character(Character const & c){
	*this = c;
	std::cout << "Character a little copy called" << std::endl;
}

Character &Character::operator=(Character const & c){
	this->haveInventorysize = 0;
	for (int i = 0; i < 4; i++){
		if(this->inventory[i])
			delete this->inventory[i];
		this->inventory[i] = c.inventory[i];
		if (c.inventory[i])
			haveInventorysize++;
	}
	this->name = c.getName();
	std::cout << "Character deep copy called" << std::endl;
	return *this;
}

std::string const &Character::getName() const{
	return this->name;
}

void Character::equip(AMateria *m){
	if (this->haveInventorysize < 4){
		this->inventory[this->haveInventorysize] = m;
		this->haveInventorysize++;
		std::cout << "Equip get type = " << m->getType() << std::endl;
	}
	else{
		std::cout << "Equip not type = " << m->getType() << 
		"nonexistent Materia, don’t do a thing." << std::endl;
	}
}

void Character::unequip(int idx){
	int i;

	i = idx + 1;
	while (i < 4 && this->inventory[i]){
		this->inventory[i - 1] = this->inventory[i];
		i++;
	}
	this->inventory[i] = NULL;
}

void Character::use(int idx, ICharacter& target){
	this->inventory[idx]->use(target);
	this->unequip(idx);
}