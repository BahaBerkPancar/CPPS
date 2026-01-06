#include "Base.hpp"



int main() {
    std::srand(std::time(NULL));

    for (int i = 0; i < 5; i++) {
        std::cout << "Test " << i + 1 << ":" << std::endl;
        Base* ptr = generate();
        
        std::cout << "Identify by pointer:   ";
        identify(ptr);
        
        std::cout << "Identify by reference: ";
        identify(*ptr);

        delete ptr;
        std::cout << "-----------------------" << std::endl;
    }
    return 0;
}