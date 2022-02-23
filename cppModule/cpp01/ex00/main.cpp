#include "Zombie.hpp"

int main()
{
	Zombie zombieStack = Zombie("stack");
	Zombie *zombieHeap = new Zombie("heap");
	Zombie *zombieNew = newZombie("newZombie");

	zombieStack.announceName();
	zombieHeap->announceName();
	zombieNew->announceName();
	randomChump("randomChump");
	delete zombieHeap;
}