#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){
	std::cout << "Cat has been created" << std::endl;
	this->brain = new Brain();
}
Cat::~Cat(){
	std::cout << "Cat has been destroyed" << std::endl;
	delete this->brain;
}

Cat& Cat::operator=(Cat &other){
	std::cout << "Cat copy constructor called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}