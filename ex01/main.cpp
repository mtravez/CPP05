#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try{
		Bureaucrat b("Mike", 5);
		Form a("permission form", 1, 4);
		b.incrementGrade(1);
		b.signForm(a);
		std::cout << a << std::endl;
		std::cout << b;
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	return 0;
}