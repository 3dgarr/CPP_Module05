#include "./Bureaucrat.hpp"
#include "./Form.hpp"

int main()
{
	try
	{
		// Form	f("someform", 150, -928);
		// Form	f("someform", 151, -928);
		// Form	f("someform", 1000, 8);
		Form	f("someform", 18, 8);
		Bureaucrat b("babken", 17);
		
		std::cout << f << std::endl;
		std::cout << b << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
		// std::cout << b << std::endl;
		// b.incrementGrade();
		// std::cout << b << std::endl;
		// b.decrementGrade();
		// std::cout << b << std::endl;
		// b.decrementGrade();
		// std::cout << b << std::endl;

	}
	catch(const Bureaucrat::GradeTooHighException& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	catch(const Form::GradeTooHighException& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	catch(const Form::GradeTooLowException& ex)
	{
		std::cerr << ex.what() << std::endl;
	}	
}