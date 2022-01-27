#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

void Zombie::announceName()
{
	std::cout << name << "BraiiiiiiinnnzzzZ..."<< std::endl;
}

Zombie :: ~Zombie()
{
	std::cout<< name << "은(는) 죽는다" <<std::endl;
}

