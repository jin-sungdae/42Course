#include "ScavTrap.hpp"

int main()
{
    ClapTrap cT("jin");
    ScavTrap gT("jon");
    ScavTrap sT("jun");

    cT.attack("sungdae");
    cT.takeDamage(5);
    cT.attack("sungdae");
    cT.beRepaired(20);
    
    gT.takeDamage(10);
    gT.attack("sungdae");
    gT.beRepaired(30);

    //sT.attack("singdae");
    sT.takeDamage(20);
    sT.attack("sungdae");
    sT.beRepaired(30);
    sT.guardGate();
}