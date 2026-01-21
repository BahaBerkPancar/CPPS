#include "MutantStack.hpp"

int myrand() {
    return std::rand() % 35;
}

int main(int ac, char **)
{
	if(ac != 1)
		return std::cout << "Usage: ./mutantstack" << std::endl, -1;

    std::srand(std::time(0));

    MutantStack<int> stack;

    std::cout << "mutant stack: ";
    for (int i = 0; i < myrand(); ++i) {
        int n = myrand();
        std::cout << n << " ";
        stack.push(n);
    }
    std::cout << std::endl;
    std::cout << "iterating stack: ";
    MutantStack<int>::iterator it = stack.begin();
    MutantStack<int>::iterator end = stack.end();

    while (it != end) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    std::cout << stack.top() << std::endl;
	stack.pop();
	std::cout << stack.size() << std::endl;

    return 0;
}
