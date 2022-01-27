#ifndef HUMANB
#define HUMANB

#include "Weapon.hpp"

class HumanB{
private:
	std::string Human_name;
	Weapon *weapon;
public:
	HumanB(std::string _Human_name);
	void setWeapon(Weapon &_weapon);
	void attack();
	~HumanB();
};

#endif