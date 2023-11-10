#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
//	try{
//		Bureaucrat b("Mike", 5);
////		AForm a("permission form", 1, 4);
////		ShrubberyCreationForm a("house");
////		RobotomyRequestForm a("Mike");
//		PresidentialPardonForm a("Mike");
//		b.signForm(a);
//		b.incrementGrade(4);
//		std::cout << a << std::endl;
//		std::cout << b << std::endl;
//		b.executeForm(a);
//	}
//	catch (std::exception &e)
//	{
//		std::cout << e.what();
//	}

	Intern randomIntern;
	AForm *rrf;
	AForm *ppf;

	rrf = randomIntern.makeForm("robotomy request", "Bender");
	ppf = randomIntern.makeForm("presidential pardon", "Mike");
	delete rrf;
	delete ppf;
	return 0;
}