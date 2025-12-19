#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) : name(name), Hit_points(10), Energy_points(10), Attack_damage(0) {
    std::cout << "ClapTrap " << name << " created!" << std::endl;
}


ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap " << name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target){
    if (Energy_points <= 0 || Hit_points <= 0) {
        std::cout << "ClapTrap " << name << " cannot attack!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " attacks " << target
              << ", causing " << Attack_damage << " points of damage!" << std::endl;
    Energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount){
    if (amount > Hit_points)
        Hit_points = 0;
    else
        Hit_points -= amount;
    std::cout << "ClapTrap " << name << " has taken " 
              << amount << " points of damage. Current HP: " << Hit_points << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (Energy_points <= 0 || Hit_points <= 0) {
        std::cout << "ClapTrap " << name << " cannot be repaired!" << std::endl;
        return;
    }
    Hit_points += amount;
    Energy_points--;
    std::cout << "ClapTrap " << name << " heals " 
              << amount << " points. Current HP: " << Hit_points << std::endl;
}
