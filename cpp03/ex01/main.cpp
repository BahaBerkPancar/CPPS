#include "ScavTrap.hpp"

int main()
{
    ScavTrap scav("Harvey");
    scav.attack("Mike");
    scav.guardGate();
    scav.takeDamage(30);
    scav.beRepaired(20);
    return 0;
}
