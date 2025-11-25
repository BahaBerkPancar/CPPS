#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "=== Creating Animals ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "\n=== Types ===" << std::endl;
    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    std::cout << "\n=== Sounds ===" << std::endl;
    i->makeSound(); // Cat sound
    j->makeSound(); // Dog sound
    meta->makeSound(); // Generic Animal sound

    std::cout << "\n=== Deleting Animals ===" << std::endl;
    delete meta; // calls Animal::~Animal()
    delete j;    // calls Dog::~Dog() then Animal::~Animal()
    delete i;    // calls Cat::~Cat() then Animal::~Animal()

    std::cout << "=== Program Finished Cleanly ===" << std::endl;
    return 0;
}
