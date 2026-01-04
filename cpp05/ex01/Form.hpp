#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
private:
    const std::string name;
    bool Signed;
    const int signGrade;
    const int executeGrade;

public:
    Form();
    Form(const std::string& name, int signGrade, int executeGrade);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();
    const std::string& getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    void beSigned(const Bureaucrat& bureaucrat);
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw() { return "Form grade is too high"; }
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw() { return "Form grade is too low"; }
    };
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif