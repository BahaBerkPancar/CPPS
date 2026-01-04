#include "AForm.hpp"


class PresidentialPardonForm : public AForm {
private:
    const std::string target;
    
public:
    PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	~PresidentialPardonForm();
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    void execute(Bureaucrat const & executor) const;
};