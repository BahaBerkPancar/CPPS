#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"


class ScavTrap: public ClapTrap
{
	private:

	public:
		ScavTrap(const std::string& name);
		~ScavTrap();

		ScavTrap& operator=(const ScavTrap& other);
		void guardGate();
		void attack(const std::string& target);
};


#endif