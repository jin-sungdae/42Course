#ifndef ZOMBIE
#define ZOMBIE
#include <iostream>
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