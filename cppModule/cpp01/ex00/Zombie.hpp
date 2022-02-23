#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

class Zombie{
private:
	std::string name;
public:

	Zombie(std::string name);
	Zombie();
	void announceName();
	~Zombie();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name );

#endif