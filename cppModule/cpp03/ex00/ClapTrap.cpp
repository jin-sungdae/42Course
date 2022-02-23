#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << Green;
    std::cout << "default constructor called" << std::endl;
    std::cout << RESET;
    this->name = "NULL";
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << Green;
    std::cout << "ClapTrap name constructor called" << std::endl;
    std::cout << RESET;
    this->name = name;
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
}

void ClapTrap::attack(std::string const & target)
{
    std::cout << RED;
    std::cout << "ClapTrap <" << this->name << "> attack <" << target << "> , causing <" << this->attackDamage << "> points of damage!" << std::endl;
    std::cout << RESET;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if ((unsigned int)energyPoints <= amount)
    {
        energyPoints = 0;
        std::cout << RED << name << " died" << RESET <<  std::endl;
    }
    else
    {
        energyPoints -= amount;
        std::cout << RED << name << "take Damage : " << amount << " present energy = " << energyPoints << RESET << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints + amount < 100)
    {
        energyPoints += amount;
    }
    else
    {
        energyPoints = 100;
    }
    
    std::cout << RED << "ClapTrap <" << this->name << "> be Repaired <" << amount << ">" << RESET <<std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << Green;
    std::cout << "ClapTrap destructor called" << std::endl;
    std::cout << RESET;
}

ClapTrap::ClapTrap(ClapTrap const & src) : name(src.name), hitPoints(src.hitPoints), energyPoints(src.energyPoints), attackDamage(src.attackDamage)
{

}

ClapTrap & ClapTrap::operator=(ClapTrap const & src)
{
    name = src.name;
    hitPoints = src.hitPoints;
    energyPoints = src.energyPoints;
    attackDamage = src.attackDamage;
    return (*this);
}