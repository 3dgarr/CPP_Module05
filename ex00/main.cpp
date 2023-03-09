#include "./Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b("babken", 150);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;

	}
	catch(const Bureaucrat::GradeTooHighException& ex)
	{
		std::cerr << ex.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException& ex)
	{
		std::cerr << ex.what() << '\n';
	}

	// try
	// {
	// 	Bureaucrat b("babken", 1);
	// 	std::cout << b << std::endl;
	// 	b.incrementGrade();
	// 	std::cout << b << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	//////////////////////////////////////////////////////
	// try
	// {
	// 	Bureaucrat b;
	// 	std::cout << b << std::endl;
	// 	b.decrementGrade();
	// 	std::cout << b << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	
	
}