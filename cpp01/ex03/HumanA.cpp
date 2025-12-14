#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
	: weapon(weapon), name(name)
{
}
HumanA::~HumanA()
{
	std::cout << this->name << " was destroyed " << std::endl;
}

void HumanA::attack()
{
	std::cout << this->name << " attacked with " << this->weapon.get_type() << std::endl;
}
