#include "./Form.hpp"


std::ostream&	operator<<(std::ostream& stream, const Form& form)
{
	std::cout << "FormName        : " << form.getFormName() << std::endl;
	std::cout << "Signature       : " << form.getSignedFlag() << std::endl;
	std::cout << "GradeForSigne   : " << form.getGradeForSigne() << std::endl;
	std::cout << "GradeForExecute : " << form.getGradeForExecute() << std::endl;
	return (stream);
}

const char*	Form::GradeTooHighException::what(void)	const throw()
{
	return ("The grade of Form is too high");
}

const char*	Form::GradeTooLowException::what(void)	const throw()
{
	return ("The grade of Form is too low");
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (_isSigned)
		throw	1;
	if (bureaucrat.getGrade() > _gradeForSigne)
		throw (Form::GradeTooHighException());
	_isSigned = true;
}


std::string	Form::getFormName(void) const
{
	return (_formName);	
}

bool	Form::getSignedFlag(void) const
{
	return (_isSigned);
}

int		Form::getGradeForSigne(void) const
{
	return (_gradeForSigne);
}

int		Form::getGradeForExecute(void) const
{
	return (_gradeForExecute);	
}

///////////////////////////////////////////////////////////////

Form::Form()
	:	_formName("UnknownForm"),
		_isSigned(false),
		_gradeForSigne(150),
		_gradeForExecute(150)
{}

Form::Form(const Form& rhs)
	:	_formName(rhs._formName),
		_isSigned(rhs._isSigned),
		_gradeForSigne(rhs._gradeForSigne),
		_gradeForExecute(rhs._gradeForExecute)	
{}

Form::Form(std::string	name, int gradeForSigne, int gradeForExecute)
	:	_formName(name),
		_isSigned(false),
		_gradeForSigne(gradeForSigne),
		_gradeForExecute(gradeForExecute)
{
	if (_gradeForExecute > 150 || _gradeForSigne > 150)
		throw (Form::GradeTooLowException());
	if (_gradeForExecute < 1 || _gradeForSigne < 1)
		throw (Form::GradeTooHighException());
}

Form&	Form::operator=(const Form& rhs)
{
	if (this != &rhs)
	{
		const_cast<std::string&>(_formName) = rhs._formName;
		_isSigned = rhs._isSigned;
		const_cast<int&>(_gradeForSigne) = rhs._gradeForSigne;
		const_cast<int&>(_gradeForExecute) = rhs._gradeForExecute;
	}
	return (*this);
}

Form::~Form()
{}
