#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

void Zombie::announceName()
{
	std::cout << RED << name << GRN << " BraiiiiiiinnnzzzZ..."<< NC << std::endl;
}

Zombie :: ~Zombie()
{
	std::cout << RED << name << GRN << " 은(는) 죽는다" << NC <<std::endl;
}

