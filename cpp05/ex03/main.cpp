#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    Intern someRandomIntern;
    Bureaucrat president("President", 1);
    AForm* rrf;
    
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        std::cout << *rrf << std::endl;
        delete rrf; // Don't forget to avoid memory leaks 
    }
    
    
    rrf = someRandomIntern.makeForm("shrubbery creation", "target");
    president.signForm(*rrf);
    president.executeForm(*rrf);
    if (rrf) {
        delete rrf;
    }
    
    return 0;
}