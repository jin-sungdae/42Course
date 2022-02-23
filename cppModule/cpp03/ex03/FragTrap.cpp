#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name){
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << Purple << "FragTrap name constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(FragTrap const & f) : ClapTrap(f)
{

}

FragTrap & FragTrap::operator=(FragTrap const & f)
{
    ClapTrap::operator=(f);
    return(*this);
}

FragTrap::FragTrap()
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    name = "NULL";
    std::cout << Purple << "FragTrap default constructor called" << RESET << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << Purple << "FragTrap destructor called" << RESET <<std::endl;
}

void FragTrap::attack(std::string const & target)
{
    std::cout << Gray << "FragTrap <" << this->name << "> attack <" << target << "> , causing <" << this->attackDamage << "> points of damage!" << Gray <<std::endl;
}



 void FragTrap::highFivesGuys(void)
 {
     std::cout << Gray << "FragTrap highFivesGuys Called" << RESET << std::endl;
 }