#include "./ShrubberyCreationForm.hpp"
#include <string>
std::ostream&	operator<<(std::ostream& stream, const ShrubberyCreationForm& form)
{
	std::cout << "FormName        : " << form.getFormName() << std::endl;
	std::cout << "Target          : " << form.getFormTarget() << std::endl;
	std::cout << "Signature       : " << form.getSignedFlag() << std::endl;
	std::cout << "GradeForSigne   : " << form.getGradeForSigne() << std::endl;
	std::cout << "GradeForExecute : " << form.getGradeForExecute() << std::endl;

	return (stream);
}

void	ShrubberyCreationForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (_isSigned)
		throw	(AForm::IsAlreadySigned());
	if (bureaucrat.getGrade() > _gradeForSigne)
		throw (AForm::GradeTooHighException());
	_isSigned = true;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat) const
{
	if (bureaucrat.getGrade() > _gradeForExecute)
		throw (AForm::GradeTooHighException());
	if (!_isSigned)
		throw (AForm::FormIsNotSigned());
	std::string fileName = _target +"_shrubbery";
	std::ofstream osTree(fileName.c_str());
	std::string		tree = \
"                             0\n\
						##\n\
						####\n\
					#o####\n\
					#####o##\n\
					#o####|#/###\n\
					####|/#o#\n\
					# }|{  #\n\
						}|{\n\
					edgghaza\n";
	osTree << tree;
	osTree.close();		
}


//////////////////////////////////////////////////////////////////////////////////////////
std::string	ShrubberyCreationForm::getFormTarget(void) const
{
	return (_target);	
}

bool	ShrubberyCreationForm::getSignedFlag(void) const
{
	return (_isSigned);
}

int		ShrubberyCreationForm::getGradeForSigne(void) const
{
	return (_gradeForSigne);
}

int		ShrubberyCreationForm::getGradeForExecute(void) const
{
	return (_gradeForExecute);	
}
//////////////////////////////////////////////////////////////////////////////////////////

ShrubberyCreationForm::ShrubberyCreationForm()
	:	AForm("ShrubberyCreationForm"),
		_target("UnknownTarget"),
		_isSigned(false),
		_gradeForSigne(145),
		_gradeForExecute(137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs)
	:	AForm::AForm(rhs),
		_target(rhs._target),
		_isSigned(rhs._isSigned),
		_gradeForSigne(rhs._gradeForSigne),
		_gradeForExecute(rhs._gradeForExecute)	
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	:	AForm("ShrubberyCreationForm"),
		_target(target),
		_isSigned(false),
		_gradeForSigne(145),
		_gradeForExecute(137)
{}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		const_cast<std::string&>(_target) = rhs._target;
		_isSigned = rhs._isSigned;
		const_cast<int&>(_gradeForSigne) = rhs._gradeForSigne;
		const_cast<int&>(_gradeForExecute) = rhs._gradeForExecute;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}
