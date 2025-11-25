#include "ScavTrap.hpp"

int main()
{
    ScavTrap scav("SC4V");
    scav.attack("Bandit");
    scav.guardGate();
    scav.takeDamage(30);
    scav.beRepaired(20);
    return 0;
}
