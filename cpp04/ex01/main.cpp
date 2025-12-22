#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const int numAnimals = 4;
    Animal* animals[numAnimals];

    for (int i = 0; i < numAnimals / 2; i++)
        animals[i] = new Dog();
    for (int i = numAnimals / 2; i < numAnimals; i++)
        animals[i] = new Cat();

    for (int i = 0; i < numAnimals; i++)
        animals[i]->makeSound();

    for (int i = 0; i < numAnimals; i++)
        delete animals[i];

    Dog basic;
    {
        Dog tmp = basic;
    }

    Cat originalCat;
    Cat copyCat;
    copyCat = originalCat;

    return 0;
}