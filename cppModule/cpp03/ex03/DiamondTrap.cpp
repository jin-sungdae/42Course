#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : _name(ClapTrap::name)
{
    ClapTrap::name += "_clap_name";
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
    std::cout << Blue<< "Diamond default constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
    std::cout << Blue << "Diamond name constructor called" << RESET << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << Blue << "Diamond destructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & d) : ClapTrap(d), ScavTrap(d), FragTrap(d), _name(d._name)
{
    std::cout << RED << "DiamondTrap copy constructor called" << RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const & d)
{
    FragTrap::operator=(d);
    _name = d._name;
    std::cout << RED << "DiamondTrap operator= called" << RESET << std::endl;
    return (*this);
}

void DiamondTrap::whoAmI(void) const
{
    std::cout << RED << "DiamondTrap name = " << _name << " ClapTrap name = " << ClapTrap::name << RESET << std::endl;
}