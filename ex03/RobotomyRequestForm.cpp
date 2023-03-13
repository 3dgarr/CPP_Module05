#include "./RobotomyRequestForm.hpp"

void	RobotomyRequestForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (_isSigned)
		throw	(AForm::IsAlreadySigned());
	if (bureaucrat.getGrade() > _gradeForSigne)
		throw (AForm::GradeTooHighException());
	_isSigned = true;
}

void	RobotomyRequestForm::execute(const Bureaucrat& bureaucrat) const
{
	if (bureaucrat.getGrade() > _gradeForExecute)
		throw (AForm::GradeTooHighException());
	if (!_isSigned)
		throw (AForm::FormIsNotSigned());
	
	std::srand(std::time(NULL));
	int index = std::rand() % 2;
	std::cout << "VROOM VROOM VROOM !!" << std::endl;
	sleep(1);
	std::string outputs[2] = {_target +" has been robotomized successfully", "Robotimy of " + _target + " failed"};
	std::cout << outputs[index] << std::endl;
	if (index == 1)
		throw	AForm::ExecutionFailed();
}

//////////////////////////////////////////////////////////////////////////////////////////

std::string	RobotomyRequestForm::getFormTarget(void) const
{
	return (_target);	
}

bool	RobotomyRequestForm::getSignedFlag(void) const
{
	return (_isSigned);
}

int		RobotomyRequestForm::getGradeForSigne(void) const
{
	return (_gradeForSigne);
}

int		RobotomyRequestForm::getGradeForExecute(void) const
{
	return (_gradeForExecute);	
}

//////////////////////////////////////////////////////////////////////////////////////////

RobotomyRequestForm::RobotomyRequestForm()
	:	AForm("RobotomyRequestForm"),
		_target("UnknownTarget"),
		_isSigned(false),
		_gradeForSigne(72),
		_gradeForExecute(45)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs)
	:	AForm::AForm(rhs),
		_target(rhs._target),
		_isSigned(rhs._isSigned),
		_gradeForSigne(rhs._gradeForSigne),
		_gradeForExecute(rhs._gradeForExecute)	
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	:	AForm("RobotomyRequestForm"),
		_target(target),
		_isSigned(false),
		_gradeForSigne(72),
		_gradeForExecute(45)
{}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs._target;
		_isSigned = rhs._isSigned;
		const_cast<int&>(_gradeForSigne) = rhs._gradeForSigne;
		const_cast<int&>(_gradeForExecute) = rhs._gradeForExecute;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}
