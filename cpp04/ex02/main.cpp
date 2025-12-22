#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    i->makeSound();
    j->makeSound();

    delete j;
    delete i;

    const int numAnimals = 4;
    Animal* animals[numAnimals];

    for (int k = 0; k < numAnimals / 2; k++)
        animals[k] = new Dog();
    for (int k = numAnimals / 2; k < numAnimals; k++)
        animals[k] = new Cat();

    for (int k = 0; k < numAnimals; k++)
        animals[k]->makeSound();

    for (int k = 0; k < numAnimals; k++)
        delete animals[k];

    return 0;
}