#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat president("President", 1);
        Bureaucrat intern("Intern", 150);
        
        RobotomyRequestForm B("Bender");
        PresidentialPardonForm c("Ford Prefect");
        ShrubberyCreationForm a("home");
        president.signForm(a);
        president.executeForm(a);
        intern.signForm(a);
        intern.executeForm(a);
        president.signForm(B);
        president.executeForm(B);
        president.executeForm(B);
        president.signForm(c);
        president.executeForm(c);
        PresidentialPardonForm unsigned_c("Arthur Dent");
        president.executeForm(unsigned_c);
    }
    catch (std::exception& e)
    {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }
    return 0;
}