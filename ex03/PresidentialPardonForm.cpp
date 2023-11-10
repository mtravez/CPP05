#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential_pardon_form", 25, 5)
{
	target = "default location";
	return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &presidentialPardonForm) : AForm(presidentialPardonForm)
{
	this->target = presidentialPardonForm.target;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("presidential_pardon_form", 25, 5)
{
	this->target = target;
	return;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &presidentialPardonForm)
{
	this->target = presidentialPardonForm.target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!this->canExecute(executor))
		return;
	std::cout << target << " was pardonded by Zaphod Beeblebrox" << std::endl;
	return;
}