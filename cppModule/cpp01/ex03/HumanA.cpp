#include "HumanA.hpp"

HumanA::HumanA(std::string _Human_name, Weapon &_weapon) : Human_name(_Human_name), weapon(_weapon)
{
}

void HumanA::attack()
{
	std::cout << Human_name << " attacks with his " << weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "end" << std::endl;
}