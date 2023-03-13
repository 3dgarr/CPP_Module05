#include "./AForm.hpp"

std::ostream&	operator<<(std::ostream& stream, const AForm& form)
{
	std::cout << "FormName        : " << form.getFormName() << std::endl;
	std::cout << "Target          : " << form.getFormTarget() << std::endl;
	std::cout << "Signature       : " << form.getSignedFlag() << std::endl;
	std::cout << "GradeForSigne   : " << form.getGradeForSigne() << std::endl;
	std::cout << "GradeForExecute : " << form.getGradeForExecute() << std::endl;

	return (stream);
}

const char*	AForm::GradeTooHighException::what(void)	const throw()
{
	return ("The grade of Form is too high");
}

const char*	AForm::GradeTooLowException::what(void)	const throw()
{
	return ("The grade of Form is too low");
}

const char*	AForm::IsAlreadySigned::what(void)	const throw()
{
	return ("The Form is already signed");
}

const char*	AForm::FormIsNotSigned::what(void)	const throw()
{
	return ("The Form is not signed to be executed");
}

const char*	AForm::ExecutionFailed::what(void)	const throw()
{
	return ("Execution failed");
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (_isSigned)
		throw	(1);
	if (bureaucrat.getGrade() > _gradeForSigne)
		throw (AForm::GradeTooHighException());
	_isSigned = true;
}


std::string	AForm::getFormName(void) const
{
	return (_formName);	
}

bool	AForm::getSignedFlag(void) const
{
	return (_isSigned);
}

int		AForm::getGradeForSigne(void) const
{
	return (_gradeForSigne);
}

int		AForm::getGradeForExecute(void) const
{
	return (_gradeForExecute);	
}


AForm::AForm()
	:	_formName("UnknownForm"),
		_isSigned(false),
		_gradeForSigne(150),
		_gradeForExecute(150)
{}

AForm::AForm(const AForm& rhs)
	:	_formName(rhs._formName),
		_isSigned(rhs._isSigned),
		_gradeForSigne(rhs._gradeForSigne),
		_gradeForExecute(rhs._gradeForExecute)	
{}

AForm::AForm(std::string name, int gradeForSigne, int gradeForExecute)
	:	_formName(name),
		_isSigned(false),
		_gradeForSigne(gradeForSigne),
		_gradeForExecute(gradeForExecute)
{
	if (_gradeForExecute > 150 || _gradeForSigne > 150)
		throw (AForm::GradeTooLowException());
	if (_gradeForExecute < 1 || _gradeForSigne < 1)
		throw (AForm::GradeTooHighException());
}

AForm::AForm(std::string name)
	:	_formName(name),
		_isSigned(false),
		_gradeForSigne(150),
		_gradeForExecute(150)
{}

AForm&	AForm::operator=(const AForm& rhs)
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

AForm::~AForm()
{}
