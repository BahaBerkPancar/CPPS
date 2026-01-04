#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
private:
    const std::string target;
public:
    RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	~RobotomyRequestForm();
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    void execute(Bureaucrat const & executor) const;
};