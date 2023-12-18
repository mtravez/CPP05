#include "AForm.hpp"

AForm::AForm() : isSigned(false), name("default"), signGrade(150), execGrade(150)
{
	return;
}

AForm::AForm(std::string name, int signGrade, int execGrade) : isSigned(false), name(name), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	if (signGrade < 0 || execGrade < 0)
		throw GradeTooHighException();
	return;
}

AForm::AForm(AForm &form) : isSigned(false), name(form.getName()), signGrade(form.getSignGrade()), execGrade(form.getExecGrade())
{
	return;
}

AForm::~AForm()
{
	return;
}

AForm &AForm::operator=(AForm &form)
{
	isSigned = form.getIsSigned();
	return *this;
}

const std::string AForm::getName() const
{
	return this->name;
}

int AForm::getExecGrade() const
{
	return this->execGrade;
}

bool AForm::getIsSigned() const
{
	return this->isSigned;
}

int AForm::getSignGrade() const
{
	return this->signGrade;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	else
		this->isSigned = true;
}

bool AForm::canExecute(Bureaucrat const &bureaucrat) const
{
	if (bureaucrat.getGrade() > this->getExecGrade())
	{
		throw GradeTooLowException();
		return false;
	}
	if (!this->getIsSigned())
	{
		throw FormNotSignedException();
		return false;
	}
	return true;
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	return;
}

std::ostream &operator<<(std::ostream& COUT, AForm const &form)
{
	COUT << RED << "Form with name " << form.getName();
	if (form.getIsSigned())
		COUT << " is signed";
	else
		COUT << " is not signed";
	COUT << ". Grade to sign: " << form.getSignGrade() << ". Grade to execute: " << form.getExecGrade() << RESET;
	return COUT;
}