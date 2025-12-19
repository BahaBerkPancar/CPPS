#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
}
HumanB::~HumanB()
{
	std::cout << this->name << " was destroyed " << std::endl;
}

void HumanB::attack()
{
	if (this->weapon == NULL)
	{
		std::cout << this->name << " no weapon to attack" << std::endl;
		return ;
	}
	std::cout << this->name << " attacked with " << this->weapon->getType() << std::endl;
}
void HumanB::set_name(std::string name)
{
	this->name = name;
}
void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}