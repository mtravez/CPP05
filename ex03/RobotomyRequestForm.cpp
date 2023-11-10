#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy_request_form", 72, 45)
{
	target = "default location";
	return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &robotomyRequestForm) : AForm(robotomyRequestForm)
{
	this->target = robotomyRequestForm.target;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("robotomy_request_form", 72, 45)
{
	this->target = target;
	return;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &robotomyRequestForm)
{
	this->target = robotomyRequestForm.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!this->canExecute(executor))
		return;
	std::cout << "*Whirr Vroom Drillll*" << std::endl;
	std::srand(static_cast<unsigned int>(std::time(0)));
	int x = std::rand() % 2;
	if (x)
		std::cout << this->target << " has been robotomized successfully\n";
	else
		std::cout << this->target << " failed to be robotomized\n";
	return;
}