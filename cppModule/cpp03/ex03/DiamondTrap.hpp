#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
public:
    DiamondTrap();
    DiamondTrap(std::string name);
    ~DiamondTrap();
    DiamondTrap(DiamondTrap const & d);
    DiamondTrap& operator=(DiamondTrap const & d);
    void whoAmI() const;
    using ScavTrap::attack;
private:
    std::string _name;
};

#endif
