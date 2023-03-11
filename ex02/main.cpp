#include "./Bureaucrat.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./AForm.hpp"

int main()
{
	try
	{
		ShrubberyCreationForm g("mission");
		Bureaucrat b("babken", 15);
		std::cout << g << std::endl;

		b.signForm(g);

		// std::cout << g << std::endl;
		// g.execute(b);
		b.executeForm(g);

	}
	catch(const Bureaucrat::GradeTooHighException& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	catch(const AForm::GradeTooHighException& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	catch(const AForm::GradeTooLowException& ex)
	{
		std::cerr << ex.what() << std::endl;
	}	
}