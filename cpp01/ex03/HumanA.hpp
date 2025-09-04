#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA{
	private:
		std::string type;
		Weapon *weapon;
		std::string name;
	public:
		HumanA(std::string name , Weapon& a);
		~HumanA();
		void attack();
};

#endif
