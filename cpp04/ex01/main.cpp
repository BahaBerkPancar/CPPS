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

    std::cout << "--- deep copy demo ---" << std::endl;
    Cat *originalCat = new Cat();
    originalCat->getBrain()->setIdea(0, "chase the mouse");

    Cat *copyCat = new Cat(*originalCat);
    Cat assignedCat;
    assignedCat = *originalCat;

    originalCat->getBrain()->setIdea(0, "sleep all day");

    std::cout << "original idea: " << originalCat->getBrain()->getIdea(0) << std::endl;
    std::cout << "copy idea:     " << copyCat->getBrain()->getIdea(0) << std::endl;
    std::cout << "assigned idea: " << assignedCat.getBrain()->getIdea(0) << std::endl;

    delete originalCat;
    copyCat->makeSound();
    delete copyCat;

    return 0;
}
