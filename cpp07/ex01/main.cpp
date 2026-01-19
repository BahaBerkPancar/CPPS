#include "iter.hpp"

int main(int ac, char *av[]) {
	(void)av;
	if(ac != 1)
		return (std::cerr << "Usage: " << av[0] << std::endl, 1);
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intLength = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "array:" << std::endl;
	iter(intArray, intLength, print);

	iter(intArray, intLength, increment);
	std::cout << "After incrementation :" << std::endl;
	iter(intArray, intLength, print);

	iter(intArray, intLength, _double);
	std::cout << "After doubling :" << std::endl;
	iter(intArray, intLength, print);

	iter(intArray, intLength, square);
	std::cout << "Square values :" << std::endl;
	iter(intArray, intLength, print);

	std::string strArray[] = {"Ts", "et", "Sr", "ti", " n", " g", "!!"};
	size_t strLength = sizeof(strArray) / sizeof(strArray[0]);

	std::cout << "Original string array:" << std::endl;
	iter(strArray, strLength, print);

	iter(strArray, strLength, ::toupper);
	std::cout << "After toupper:" << std::endl;
	iter(strArray, strLength, print);

	return 0;
}