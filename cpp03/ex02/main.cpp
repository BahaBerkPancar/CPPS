#include "FragTrap.hpp"

int main() {
    std::cout << "---- Creating FragTrap ----" << std::endl;
    FragTrap frag("FR4G-TP");

    std::cout << "\n---- Basic Actions ----" << std::endl;
    frag.attack("Bandit");
    frag.takeDamage(30);
    frag.beRepaired(20);

    std::cout << "\n---- Special Ability ----" << std::endl;
    frag.highFivesGuys();

    std::cout << "\n---- Copying FragTrap ----" << std::endl;
    FragTrap copyFrag(frag);
    copyFrag.attack("Skag");

    std::cout << "\n---- Assignment ----" << std::endl;
    FragTrap assignedFrag("Dummy");
    assignedFrag = frag;
    assignedFrag.attack("Rakk");

    std::cout << "\n---- Destruction ----" << std::endl;
    return 0;
}
