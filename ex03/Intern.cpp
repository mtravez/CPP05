#include "Intern.hpp"

Intern::Intern()
{
	return;
}

Intern::Intern(Intern &intern)
{
	(void) intern;
	return;
}

Intern::~Intern()
{
	return;
}

Intern &Intern::operator=(Intern &intern)
{
	(void) intern;
	return *this;
}

AForm *Intern::makeForm(std::string form, std::string target)
{
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i = 0;
	AForm *internform = NULL;
	for (i = 0; i < 3; i++)
	{
		if (formNames[i].compare(form) == 0)
			break;
	}
	switch (i) {
		case 0:
			internform = new ShrubberyCreationForm(target);
			break;
		case 1:
			internform = new RobotomyRequestForm(target);
			break;
		case 2:
			internform = new PresidentialPardonForm(target);
			break;
		default:
			std::cout << "Intern couldn't create '" << form << "' form because it doesn't exist\n";
			return (NULL);
	}
	std::cout << "Intern creates " << form << " form" << std::endl;
	return internform;
}