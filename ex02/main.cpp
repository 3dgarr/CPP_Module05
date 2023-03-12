#include "./Bureaucrat.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./AForm.hpp"

int main()
{
	try
	{
		// ShrubberyCreationForm	shurb("mission");
		// RobotomyRequestForm		robot("passport");
		// Bureaucrat bur("babken", 15);
		// std::cout << shurb << std::endl;

		// bur.signForm(shurb);

		// std::cout << shurb << std::endl;
		// shurb.execute(bur);
		// bur.executeForm(shurb);

		RobotomyRequestForm	robot("passport");
		Bureaucrat			bur("babken", 15);

		std::cout << robot << std::endl;
		bur.executeForm(robot);
		bur.signForm(robot);
		std::cout << robot << std::endl;
		bur.executeForm(robot);

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