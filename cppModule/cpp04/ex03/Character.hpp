#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter{
public:
	Character(std::string const &name);
	Character(Character const & c);
	~Character();
	Character &operator=(Character const & c);
	virtual std::string const &getName()const;
	virtual void equip(AMateria *m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter &target);
private:
	Character();
	std::string name;
	AMateria *inventory[4];
	int haveInventorysize;

};

#endif