#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat a("Kenny", 2);
    Bureaucrat b;

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    b = a;
    std::cout << b << std::endl;

    try
    {
        a.incrementGrade();
        std::cout << a << std::endl;
        a.incrementGrade();
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Specific Error: " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "General Error: " << e.what() << std::endl;
    }

    return 0;
}