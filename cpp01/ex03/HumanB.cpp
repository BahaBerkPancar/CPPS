#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
}
HumanB::~HumanB()
{
	std::cout << this->name << " was destroyed " << std::endl;
}

void HumanB::attack()
{
	std::cout << this->name << " attacked with " << this->weapon->get_type() << std::endl;
}
void HumanB::set_name(std::string name)
{
	this->name = name;
}
void HumanB::setWeapon(Weapon& b)
{
	this->weapon = &b;
}