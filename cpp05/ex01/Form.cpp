#include "Form.hpp"

Form::Form() : name("Default"), Signed(false), signGrade(150), executeGrade(150) {}

Form::Form(const std::string& name, int signGrade, int executeGrade)
    : name(name), Signed(false), signGrade(signGrade), executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw Form::GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& other)
    : name(other.name), Signed(other.Signed),
      signGrade(other.signGrade), executeGrade(other.executeGrade) {}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        this->Signed = other.Signed;
    return *this;
}

Form::~Form() {}

const std::string& Form::getName() const {
    return name;
}
bool Form::getIsSigned() const {
    return Signed;
}
int Form::getSignGrade() const {
    return signGrade;
}
int Form::getExecuteGrade() const {
    return executeGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > signGrade)
        throw Form::GradeTooLowException();
    Signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form: " << form.getName() << ", signed: " << (form.getIsSigned() ? "yes" : "no")
       << ", sign grade: " << form.getSignGrade() << ", execute grade: " << form.getExecuteGrade();
    return os;
}