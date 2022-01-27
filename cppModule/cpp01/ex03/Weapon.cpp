#include "Weapon.hpp"

void Weapon::setType(std::string _type)
{
	type = _type;
}

std::string &Weapon::getType()
{
	return type;
}

Weapon::Weapon(std::string _type) : type(_type){}

Weapon::~Weapon()
{

}
