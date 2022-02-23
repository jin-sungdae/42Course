#include "Zombie.hpp"

int main()
{
	Zombie *zombie = zombieHorde(5, "zombie");
	for (int i = 0; i < 5 ; i++)
		zombie[i].announceName();
	delete[] zombie;
}