#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>


class Weapon{
private:
	std::string type;

public:
	Weapon(std::string type);
	Weapon();
	void setType(std::string _type);
	std::string &getType();
	~Weapon();

};

#endif