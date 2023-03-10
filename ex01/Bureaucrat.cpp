#include "./Bureaucrat.hpp"

/////////////////////////////////////////////////////////////////////

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The grade of bureaucrat is too high");
}


const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The grade of bureaucrat is too low");
}

/////////////////////////////////////////////////////////////////////

void	Bureaucrat::signForm(const std::string& formName, int formGrade) const
{
	if (_grade > formGrade)
		std::cout << "bureaucrat " << _name <<  " couldn't sign form " << formName << ", because " << std::flush;
	else
		std::cout <<  "Bureaucrat " << _name << " signed form " << formName << std::endl;	
}


std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

int		Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	if (_grade == MAXGRADE)
		throw GradeTooHighException();
	_grade --;
}

void	Bureaucrat::decrementGrade(void)
{
	if (_grade == MINGRADE)
		throw GradeTooLowException();
	_grade++;
}

/////////////////////////////////////////////////////////////////////

Bureaucrat::Bureaucrat()
	:	_name("Unnamed"),
		_grade(150),
		MINGRADE(150),
		MAXGRADE(1)
{}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs)
	:	_name(rhs._name),
		_grade(rhs._grade),
		MINGRADE(150),
		MAXGRADE(1)
{}

Bureaucrat::Bureaucrat(const std::string name, int grade)
	:	_name(name),
		_grade(grade),
		MINGRADE(150),
		MAXGRADE(1)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw	GradeTooLowException();
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
	{
		const_cast<std::string&>(_name) = rhs._name;
		_grade = rhs._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{}

std::ostream& operator<<(std::ostream &stream, const Bureaucrat& bureaucrat)
{
	stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (stream);
}