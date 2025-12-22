#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain()){
	std::cout << "Cat has been created" << std::endl;
}

Cat::~Cat(){
	delete brain;
	std::cout << "Cat has been destroyed" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*(other.brain))){
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other){
	if (this != &other){
		Animal::operator=(other);
		*brain = *(other.brain);
	}
	std::cout << "Cat assignment operator called" << std::endl;
	return *this;
}

void Cat::makeSound() const {
    std::cout << "meow meow" << std::endl;
}