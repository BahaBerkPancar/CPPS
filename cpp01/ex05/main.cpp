#include "Harl.hpp"

int main()
{
    Harl harl;

    std::cout << "DEBUG level:" << std::endl;
    harl.complain("DEBUG");

    std::cout << "\nINFO level:" << std::endl;
    harl.complain("INFO");

    std::cout << "\nWARNING level:" << std::endl;
    harl.complain("WARNING");

    std::cout << "\nERROR level:" << std::endl;
    harl.complain("ERROR");

    std::cout << "\nUNKNOWN level:" << std::endl;
    harl.complain("HARL");

    return 0;
}
