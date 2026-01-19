#include "Array.hpp"
#include <iostream>

int main() {
    Array<int> empty;
    Array<int> numbers(5);

    std::cout << "Empty size: " << empty.size() << std::endl;
    std::cout << "Numbers size: " << numbers.size() << std::endl;

    for (unsigned int i = 0; i < numbers.size(); i++) {
        numbers[i] = i * 2;
    }

    std::cout << "Numbers: ";
    for (unsigned int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    Array<int> copy(numbers);
    copy[0] = 42;
    std::cout << "Original[0]: " << numbers[0] << std::endl;
    std::cout << "Copy[0]: " << copy[0] << std::endl;

    Array<int> assigned;
    assigned = numbers;
    assigned[0] = 99;
    std::cout << "Original[0]: " << numbers[0] << std::endl;
    std::cout << "Assigned[0]: " << assigned[0] << std::endl;

    try {
        std::cout << numbers[10] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << numbers[-1] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}