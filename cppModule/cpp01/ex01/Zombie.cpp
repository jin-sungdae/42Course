#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

void Zombie::announceName()
{
	std::cout << "<" << this->name << ">" << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "<" << this->name << ">" << " delete" << std::endl;
}

void Zombie::set_Name(std::string _name)
{
	this->name = _name;
}

Zombie::Zombie()
{
	std::cout << "make zombie" << std::endl;
}