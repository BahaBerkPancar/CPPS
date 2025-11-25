#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){
	std::cout << "Dog has been created" << std::endl;
}

Dog::~Dog(){
	std::cout << "Dog has been destroyed" << std::endl;
}

