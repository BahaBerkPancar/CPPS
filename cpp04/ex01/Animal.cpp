#include "Animal.hpp"

Animal::Animal() : type("Animal"){
	std::cout << "Animal has been created" << std::endl;
}

Animal::Animal(std::string type) : type(type){
	std::cout << "Animal has been created" << std::endl;
}

Animal::~Animal(){
	std::cout << "Animal has been destroyed" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal copy constructor called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

void Animal::makeSound() const{
	if (this->type == "Dog")
		std::cout << "Bark Bark Woof Woof" << std::endl;
	else if (this->type == "Cat")
		std::cout << "meow meow" << std::endl;
	else
		std::cout << this->type << " noises" << std::endl;
}

std::string Animal::getType() const{
	return(this->type);
}

void Animal::setType(std::string type){
	this->type = type;
}