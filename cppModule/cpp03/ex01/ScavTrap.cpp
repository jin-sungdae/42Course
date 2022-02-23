#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << Yellow;
    std::cout << "ScavTrap name constructor called" << std::endl;
    std::cout << RESET;
}

ScavTrap::ScavTrap() : ClapTrap()
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    name = "NULL";
    std::cout << Yellow;
    std::cout << "ScavTrap default constructor called" << std::endl;
    std::cout << RESET;
}

ScavTrap::ScavTrap(ScavTrap const & s) : ClapTrap(s)
{

}

ScavTrap& ScavTrap::operator=(ScavTrap const& s)
{
    ClapTrap::operator=(s);
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << Yellow;
    std::cout << "ScavTrap destructor called" << std::endl;
    std::cout << RESET;
}

void ScavTrap::attack(std::string const & target)
{
    std::cout << Blue <<  "ScavTrap <" << this->name << "> attack <" << target << "> , causing <" << this->attackDamage << "> points of damage!" << RESET << std::endl;
}

void ScavTrap::guardGate()
{
    if(energyPoints)
        std::cout << Blue << "guardGateOpen" << RESET << std::endl;
    else
        std::cout << Blue << "not guardGateOpen" << RESET << std::endl;
}


