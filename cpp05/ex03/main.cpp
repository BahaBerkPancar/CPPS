#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main() {
    Intern someRandomIntern;
    AForm* rrf;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        std::cout << *rrf << std::endl;
        delete rrf; // Don't forget to avoid memory leaks 
    }

    rrf = someRandomIntern.makeForm("unknown form", "target");
    if (rrf) {
        delete rrf;
    }

    return 0;
}