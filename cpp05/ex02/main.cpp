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
        
        ShrubberyCreationForm a("home");
        RobotomyRequestForm B("Bender");
        PresidentialPardonForm c("Ford Prefect");
        intern.signForm(a);
        intern.executeForm(a);
        president.signForm(a);
        president.executeForm(a);
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