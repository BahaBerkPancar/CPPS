#include "Zombie.hpp"

void Zombie::announce(void){
	std::cout<< Zombie::name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
	std::cout << name << " is destroyed." << std::endl;
}

Zombie::Zombie( std::string n): name(n){
}