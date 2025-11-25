#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){
	std::cout << "Cat has been created" << std::endl;
}
Cat::~Cat(){
	std::cout << "Cat has been destroyed" << std::endl;
}