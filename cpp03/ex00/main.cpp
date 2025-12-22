#include "ClapTrap.hpp"

int main() {
    ClapTrap clap("Harvey");

    clap.attack("Luis");
    clap.takeDamage(3);
    clap.beRepaired(5);

    ClapTrap clap2("Mike");
    clap2.attack("Jessica");
    clap2.takeDamage(7);
    clap2.beRepaired(2);
    return 0;
}
