#include "./PresidentialPardonForm.hpp"

void	PresidentialPardonForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (_isSigned)
		throw	(AForm::IsAlreadySigned());
	if (bureaucrat.getGrade() > _gradeForSigne)
		throw (AForm::GradeTooHighException());
	_isSigned = true;
}

void	PresidentialPardonForm::execute(const Bureaucrat& bureaucrat) const
{
	if (bureaucrat.getGrade() > _gradeForExecute)
		throw (AForm::GradeTooHighException());
	if (!_isSigned)
		throw (AForm::FormIsNotSigned());
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	

}


//////////////////////////////////////////////////////////////////////////////////////////
std::string	PresidentialPardonForm::getFormTarget(void) const
{
	return (_target);	
}

bool	PresidentialPardonForm::getSignedFlag(void) const
{
	return (_isSigned);
}

int		PresidentialPardonForm::getGradeForSigne(void) const
{
	return (_gradeForSigne);
}

int		PresidentialPardonForm::getGradeForExecute(void) const
{
	return (_gradeForExecute);	
}
//////////////////////////////////////////////////////////////////////////////////////////

PresidentialPardonForm::PresidentialPardonForm()
	:	AForm("PresidentialPardonForm"),
		_target("UnknownTarget"),
		_isSigned(false),
		_gradeForSigne(25),
		_gradeForExecute(5)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs)
	:	AForm::AForm(rhs),
		_target(rhs._target),
		_isSigned(rhs._isSigned),
		_gradeForSigne(rhs._gradeForSigne),
		_gradeForExecute(rhs._gradeForExecute)	
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	:	AForm("PresidentialPardonForm"),
		_target(target),
		_isSigned(false),
		_gradeForSigne(25),
		_gradeForExecute(5)
{}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
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

PresidentialPardonForm::~PresidentialPardonForm()
{}
