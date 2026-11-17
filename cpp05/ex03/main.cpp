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
    if (rrf) {
        president.signForm(*rrf);
        president.executeForm(*rrf);
        delete rrf;
    }

    rrf = someRandomIntern.makeForm("coffee request", "Bender");
    if (rrf) {
        std::cout << "unexpected: unknown form was created" << std::endl;
        delete rrf;
    } else {
        std::cout << "makeForm returned NULL for the unknown form" << std::endl;
    }

    return 0;
}