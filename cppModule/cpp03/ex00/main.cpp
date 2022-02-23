#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap("jin");
    clapTrap.attack("sungdae");
    clapTrap.takeDamage(5);
    clapTrap.attack("sungdae");
    clapTrap.beRepaired(20);
}