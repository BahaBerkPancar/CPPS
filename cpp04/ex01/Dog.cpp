#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){
	std::cout << "Dog has been created" << std::endl;
	this->brain = new Brain();
}

Dog::~Dog(){
	std::cout << "Dog has been destroyed" << std::endl;
	delete this->brain;
}

Dog& Dog::operator=(Dog &other){
	std::cout << "Dog copy constructor called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}