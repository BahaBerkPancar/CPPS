#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class AForm
{
private:
    const std::string name;
    bool              Signed;
    const int         signGrade;
    const int         executeGrade;

public:
    AForm();
    AForm(const std::string& name, int signGrade, int executeGrade);
    AForm(const AForm& other);
    virtual ~AForm();
    AForm& operator=(const AForm& other);
    const std::string& getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    void beSigned(const Bureaucrat& bureaucrat);
    virtual void execute(Bureaucrat const & executor) const = 0;

    class GradeTooHighException : public std::exception {
        public: virtual const char* what() const throw() {
            return "Grade is too high";
        }
    };

    class GradeTooLowException : public std::exception {
        public: virtual const char* what() const throw() {
            return "Grade is too low";
        }
    };
    
    class FormNotSignedException : public std::exception {
        public: virtual const char* what() const throw() {
            return "Form is not signed";
        }
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif