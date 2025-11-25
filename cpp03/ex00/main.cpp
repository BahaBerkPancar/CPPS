#include "ClapTrap.hpp"

int main() {
    ClapTrap clap("CL4P-TP");

    clap.attack("Bandit");
    clap.takeDamage(3);
    clap.beRepaired(5);

    ClapTrap clap2("FR4G-TP");
    clap2.attack("Skag");
    clap2.takeDamage(7);
    clap2.beRepaired(2);

    return 0;
}
