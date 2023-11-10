#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	Intern(Intern &intern);
	~Intern();
	Intern &operator=(Intern &intern);

	AForm *makeForm(std::string form, std::string target);
};