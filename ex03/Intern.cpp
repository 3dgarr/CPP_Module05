#include "./Intern.hpp"

int	Intern::getFunctionIndex(const std::string fName) const
{
	const std::string functionNames[] = 
	{
		"ShrubberyCreationForm", 
		"PresidentialPardonForm", 
		"RobotomyRequestForm", 
	};
	int	i = -1;
	while (++i < 3 && fName != functionNames[i])
	;
	return (i);
}

AForm*	Intern::makeShrubberyCreationForm(const std::string target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makePresidentialPardonForm(const std::string target) const
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeRobotomyRequestForm(const std::string target) const
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makeForm(const std::string formName, const std::string target) const
{
	const FormMakers	FormMakersPtrs[] = 
	{
		&Intern::makeShrubberyCreationForm, 
		&Intern::makePresidentialPardonForm, 
		&Intern::makeRobotomyRequestForm, 
	};

	int	index = getFunctionIndex(formName);
	try
	{
		if (index == 3)
		{
			throw UndefinedFunctionName();
		}
		return((this->*(FormMakersPtrs[index]))(target));
	}
	catch(const Intern::UndefinedFunctionName& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (NULL);
}

Intern::Intern()
{}

Intern::~Intern()
{}

Intern::Intern(const Intern& rhs)
{
	(void) rhs;
}

Intern&	Intern::operator=(const Intern& rhs)
{
	(void) rhs;
	return (*this);
}

const char*	Intern::UndefinedFunctionName::what(void) const throw()
{
	const char *err = "Undefined Form Name";
	return (err);
}
