#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap d1("jin");
    DiamondTrap d2("jon");
    DiamondTrap d3("jun");

    d1.whoAmI();
    d2.whoAmI();
    d3.whoAmI();

    std::cout << "\n";
    d1.highFivesGuys();
    d2.highFivesGuys();
    d3.highFivesGuys();
    std::cout << "\n";

    d1.attack("sung");
    d1.takeDamage(10);
    d1.beRepaired(10);
    std::cout << "\n";
    d2.attack("sing");
    d2.takeDamage(20);
    d2.beRepaired(20);
    std::cout << "\n";
    d3.attack("sang");
    d3.takeDamage(30);
    d3.beRepaired(30);

    std::cout << "\n";
    d1.guardGate();
    d2.guardGate();
    d3.guardGate();
    DiamondTrap d4(d1);
    DiamondTrap d5;
    d4.whoAmI();
    d5 = d2;
    d5.whoAmI();

}