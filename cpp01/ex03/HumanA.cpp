#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& a)
{
	this->name = name;
	this->weapon = &a;
}
HumanA::~HumanA()
{
	std::cout << this->name << " was destroyed " << std::endl;
}

void HumanA::attack()
{
	std::cout << this->name << " attacked with " << this->weapon->get_type() << std::endl;
}
