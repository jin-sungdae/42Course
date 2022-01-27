#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombie = new Zombie[N];
	int i;

	i = 0;
	
	while (i < N)
	{
		std::stringstream str;
		str << (i + 1);
		zombie[i].set_Name(name + str.str());
		i++;
	}
	return zombie;
}