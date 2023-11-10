#pragma once

#include "AForm.hpp"
#include <ctime>

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm &robotomyRequestForm);
	~RobotomyRequestForm();
	RobotomyRequestForm &operator=(RobotomyRequestForm &robotomyRequestForm);

	void execute(const Bureaucrat & executor) const;
private:
	std::string target;
};