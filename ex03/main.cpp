#include "./Bureaucrat.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./AForm.hpp"
#include "./Intern.hpp"

// 		FORM_NAMES_FOR_MAKEFORM_FUNCTION
		// "ShrubberyCreationForm", 
		// "PresidentialPardonForm", 
		// "RobotomyRequestForm", 

int main()
{
	try
	{

		Intern  	someRandomIntern;
		Bureaucrat	bur("babken", 15);
		AForm*		rrf;

		rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
		
		(rrf ? std::cout << *rrf << std::endl : std::cout << "NULL" << std::endl);
		// std::cout << *rrf << std::endl;
		delete rrf;
		rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "Edgar");
		(rrf ? std::cout << *rrf << std::endl : std::cout << "NULL" << std::endl );
		// std::cout << *rrf << std::endl;
		delete rrf;
		rrf = someRandomIntern.makeForm("PresidentialPardonForm", "Vzgo");
		// std::cout << *rrf << std::endl;
		(rrf ? std::cout << *rrf << std::endl : std::cout << "NULL" << std::endl );

		delete rrf;
		rrf = someRandomIntern.makeForm("blah", "Vzgo");
		(rrf ? std::cout << *rrf << std::endl : std::cout << "NULL" << std::endl );
		delete rrf;
		
	}
	catch(const Bureaucrat::GradeTooHighException& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	catch(...)
	{
		std::cerr << "something went wrong ;)"<< std::endl;
	}
}