#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name){
	Hit_points = 100;
    Energy_points = 50;
    Attack_damage = 20;
    std::cout << "ScavTrap " << name << " created!" << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap " << name << " destroyed!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        name = other.name;
        Hit_points = other.Hit_points;
        Energy_points = other.Energy_points;
        Attack_damage = other.Attack_damage;
    }
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (Energy_points > 0 && Hit_points > 0)
    {
        std::cout << "ScavTrap " << name << " attacks " << target
                  << ", causing " << Attack_damage << " points of damage!" << std::endl;
        Energy_points--;
    }
    else
    {
        std::cout << "ScavTrap " << name << " has no energy or is dead!" << std::endl;
    }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate Keeper mode!" << std::endl;
}