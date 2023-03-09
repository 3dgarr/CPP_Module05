#include "./Bureaucrat.hpp"

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
		// throw exception
	_grade --;
}

void	Bureaucrat::decrementGrade(void)
{
	if (_grade == MINGRADE)
		//throw exception
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
	// if (_grade)
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

std::ostream& operator<<(std::ostream &stream, const Bureaucrat& b)
{
	stream << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (stream);
}