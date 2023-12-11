#include "Bureaucrat.hpp"

int main()
{
	try{
		Bureaucrat a;
		Bureaucrat b("Mike", 5);
		b.incrementGrade(4);
//		b.decrementGrade(1);
		std::cout << b;
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	return 0;
}