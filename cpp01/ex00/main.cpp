#include "Zombie.hpp"

int main() {
    Zombie stackZombie("Stacky");
    stackZombie.announce();
	
    Zombie* heapZombie = newZombie("Heapster");
    heapZombie->announce();
    randomChump("Chumpy");
    delete heapZombie;
    return 0;
}
