#pragma once

#include "AForm.hpp"
#include <ctime>

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm &presidentialPardonForm);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(PresidentialPardonForm &presidentialPardonForm);

	void execute(const Bureaucrat & executor) const;
private:
	std::string target;
};