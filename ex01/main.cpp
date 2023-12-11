#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try{
		Bureaucrat b("Mike", 5);
		Form a("permission form", 4, 4);
		b.incrementGrade(1);
//		a.beSigned(b);
		b.signForm(a);
		std::cout << a << std::endl;
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	return 0;
}