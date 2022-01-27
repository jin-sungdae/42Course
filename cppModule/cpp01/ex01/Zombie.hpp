#ifndef ZOMBIE
#define ZOMBIE
#include <iostream>
#include <sstream>

class Zombie{
private:
	std::string name;
public:
	Zombie();
	Zombie(std::string name);
	void set_Name(std::string _name);
	void announceName();
	~Zombie();
};

Zombie* zombieHorde( int N, std::string name );

#endif