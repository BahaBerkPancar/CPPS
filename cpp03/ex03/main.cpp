#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap diamond("Harvey");
    diamond.whoAmI();
    diamond.attack("Luis");
    diamond.takeDamage(40);
    diamond.beRepaired(20);
    diamond.guardGate();
    diamond.highFivesGuys();
    DiamondTrap copy(diamond);
    copy.whoAmI();
    return 0;
}