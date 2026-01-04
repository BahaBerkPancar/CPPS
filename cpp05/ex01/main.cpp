#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat boss("Boss", 1);
        Bureaucrat worker("Worker", 150);
        Form importantForm("Form", 50, 50);

        std::cout << boss << std::endl;
        std::cout << worker << std::endl;
        std::cout << importantForm << std::endl;
        worker.signForm(importantForm);
        boss.signForm(importantForm);
        std::cout << importantForm << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}