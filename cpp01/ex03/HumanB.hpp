#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB{
	private:
		std::string type;
		std::string name;
		Weapon *weapon;
	public:
		void set_name(std::string);
		void setWeapon(Weapon &);
		HumanB(std::string);
		~HumanB();
		void attack();
};
#endif