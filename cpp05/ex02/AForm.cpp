#include "AForm.hpp"

AForm::AForm() : name("Default"), Signed(false), signGrade(150), executeGrade(150) {}

AForm::AForm(const std::string& name, int signGrade, int executeGrade)
    : name(name), Signed(false), signGrade(signGrade), executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw AForm::GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : name(other.name), Signed(other.Signed), 
      signGrade(other.signGrade), executeGrade(other.executeGrade) {}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        this->Signed = other.Signed;
    return *this;
}

const std::string& AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return Signed; }
int AForm::getSignGrade() const { return signGrade; }
int AForm::getExecuteGrade() const { return executeGrade; }

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > signGrade)
        throw AForm::GradeTooLowException();
    Signed = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "Form " << form.getName() << " (signed: " << (form.getIsSigned() ? "yes" : "no")
       << ", sign-grade: " << form.getSignGrade()
       << ", exec-grade: " << form.getExecuteGrade() << ")";
    return os;
}