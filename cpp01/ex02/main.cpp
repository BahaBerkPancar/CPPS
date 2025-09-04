#include <iostream>
#include <string>

int main()
{
	std::string brian = "HI THIS IS BRIAN";
	std::string *pointer = &brian;
	std::string& reference = brian;

	std::cout << "STRING ITSELF :" << brian  << std::endl;
	std::cout << "POINTER TO THE STRING :" << pointer << std::endl;
	std::cout << "REFERENCE TO THE STRING :" << &reference << std::endl;

}