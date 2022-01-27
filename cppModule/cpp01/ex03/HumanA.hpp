#ifndef HUMANA
#define HUMANA

#include "Weapon.hpp"

class HumanA{
private:
	std::string Human_name;
	Weapon &weapon;
public:
	HumanA();
	HumanA(std::string _Human_name, Weapon &_weapon);
	void attack();
	~HumanA();
};

#endif