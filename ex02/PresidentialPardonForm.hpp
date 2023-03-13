#pragma once

#include "./AForm.hpp"
#include <exception>

class PresidentialPardonForm :  public AForm
{
	public:
		void		execute(const Bureaucrat&) const;
		void		beSigned(const Bureaucrat&);
		std::string	getFormTarget(void) const;
		bool		getSignedFlag(void) const;
		int			getGradeForSigne(void) const;	
		int			getGradeForExecute(void) const;	
		
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm&);
		PresidentialPardonForm(const std::string);
		PresidentialPardonForm& operator=(const PresidentialPardonForm&);
		~PresidentialPardonForm();

	private:
		std::string			_target;
		bool				_isSigned;
		const int			_gradeForSigne;
		const int			_gradeForExecute;
};
