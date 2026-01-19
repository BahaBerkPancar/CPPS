#include "Template.hpp"

int main() {
	int a = 2;
	int b = 3;

	std::cout << "a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "After swap" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min : " << ::min(a, b) << std::endl;
	std::cout << "max :" << ::max(a, b) << std::endl;

	std::string c = "Test1";
	std::string d = "Test2";
	
	std::cout << "c = " << c << ", d = " << d << std::endl;
	swap(c, d);
	std::cout << "After swap" << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min :" << ::min(c, d) << std::endl;
	std::cout << "max :" << ::max(c, d) << std::endl;

	return 0;
}
