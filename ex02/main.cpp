#include "./Bureaucrat.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"
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

		RobotomyRequestForm		robot("passport");
		ShrubberyCreationForm	shurb("mission");
		PresidentialPardonForm	president("pastatukht");
		

		Bureaucrat			bur("babken", 3);

		bur.signForm(shurb);
		bur.executeForm(shurb);
		// std::cout << robot << std::endl;
		// bur.executeForm(robot);
		// bur.signForm(robot);
		// std::cout << robot << std::endl;
		// bur.executeForm(robot);
		// bur.executeForm(president);
		// bur.signForm(president);
		// bur.executeForm(president);
	}
	catch(const Bureaucrat::GradeTooHighException& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
}