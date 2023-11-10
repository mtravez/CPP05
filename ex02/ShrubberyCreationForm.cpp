#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery_creation_form", 145, 137)
{
	target = "default location";
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &shrubberyCreationForm) : AForm(shrubberyCreationForm)
{
	this->target = shrubberyCreationForm.target;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("shrubbery_creation_form", 145, 137)
{
	this->target = target;
	return;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &shrubberyCreationForm)
{
	this->target = shrubberyCreationForm.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!this->canExecute(executor))
		return;
	std::ofstream place((target + "_shrubbery").c_str());
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			place << "   ^   " << "  ";
		place << std::endl;
		for (int j = 0; j < 4; j++)
			place << "  ^^^  " << "  ";
		place << std::endl;
		for (int j = 0; j < 4; j++)
			place << " ^^^^^ " << "  ";
		place << std::endl;
		for (int j = 0; j < 4; j++)
			place << "^^^^^^^" << "  ";
		place << std::endl;
		for (int j = 0; j < 4; j++)
			place << "   |   " << "  ";
		place << std::endl;
		place << std::endl;
	}
	place.close();
	return;
}