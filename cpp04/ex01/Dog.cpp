#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain()){
	std::cout << "Dog has been created" << std::endl;
}

Dog::~Dog(){
	delete brain;
	std::cout << "Dog has been destroyed" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*(other.brain))){
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other){
	if (this != &other){
		Animal::operator=(other);
		*brain = *(other.brain);
	}
	std::cout << "Dog assignment operator called" << std::endl;
	return *this;
}

void Dog::makeSound() const {
    std::cout << "Bark Bark Woof Woof" << std::endl;
}
