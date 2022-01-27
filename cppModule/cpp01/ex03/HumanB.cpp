#include "HumanB.hpp"

HumanB::HumanB(std::string _Human_name) : Human_name(_Human_name) , weapon(NULL)
{
}

void HumanB::setWeapon(Weapon &_weapon)
{
	this->weapon = &_weapon;
}

void HumanB::attack()
{
	std::cout << Human_name << " attacks with his " << weapon->getType() << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "end" << std::endl;
}