#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(ScavTrap const & s);
    ~ScavTrap();
    ScavTrap & operator=(ScavTrap const& s);

    void attack(std::string const & target);
    void guardGate();
private:
};

#endif