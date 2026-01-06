#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
        return ( std::cerr << "Usage: ./convert <value>" << std::endl, 1);
    ScalarConverter::convert(argv[1]);
    return 0;
}