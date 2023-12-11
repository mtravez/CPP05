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
	AForm *scf;

	rrf = randomIntern.makeForm("robotomy request", "Bender");
	ppf = randomIntern.makeForm("presidential pardon", "Mike");
	scf = randomIntern.makeForm("shrubbery creation", "Dave");
	delete rrf;
	delete ppf;
	delete scf;
	return 0;
}