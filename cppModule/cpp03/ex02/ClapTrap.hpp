#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

#define Green "\e[32m"
#define Yellow "\e[33m"
#define RESET "\e[0m"
#define RED "\e[31m"
#define Blue "\e[34m"
#define Purple "\e[35m"
#define Gray "\e[37m"

class ClapTrap{
public:
    void attack(std::string const & target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);


    ClapTrap();
    ClapTrap(std::string name);
    ~ClapTrap();
    ClapTrap(ClapTrap const & src);
    ClapTrap & operator=(ClapTrap const & src);

protected:
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;
};

#endif