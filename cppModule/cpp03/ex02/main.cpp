#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap cT("jin");

    cT.takeDamage(5);
    cT.attack("sungdae");

    cT.beRepaired(20);
    ScavTrap sT("jun");
    sT.takeDamage(20);
    sT.attack("singdae");
 
    sT.beRepaired(30);
    FragTrap fT("jan");
    fT.takeDamage(39);
    fT.attack("suksuksuk");
 
    fT.beRepaired(100);
}