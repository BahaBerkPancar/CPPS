#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: Invalid number of arguments." << std::endl;
		return 1;
	}
	RPN rpn;
	try
	{
		std::cout << rpn.Process(av[1]) << std::endl;
	}
	catch (const std::exception &e)
	{
		return (std::cerr << e.what() << std::endl, 1);
	}

}
