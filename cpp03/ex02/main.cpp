#include "FragTrap.hpp"

int main() {
    FragTrap frag("Harvey");

    frag.attack("Bandit");
    frag.takeDamage(30);
    frag.beRepaired(20);

    frag.highFivesGuys();

    FragTrap copyFrag(frag);
    copyFrag.attack("Luis");

    FragTrap assignedFrag("Mike");
    assignedFrag = frag;
    assignedFrag.attack("Jessica");
    return 0;
}
