#pragma once

#include "./AForm.hpp"
#include <fstream>
#include <exception>


class ShrubberyCreationForm :  public AForm
{
	public:
		void		execute(const Bureaucrat&) const;
		void		beSigned(const Bureaucrat&);
		std::string	getFormTarget(void) const;
		bool		getSignedFlag(void) const;
		int			getGradeForSigne(void) const;	
		int			getGradeForExecute(void) const;	
		
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm&);
		ShrubberyCreationForm(const std::string);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);
		~ShrubberyCreationForm();

	private:
		std::string			_target;
		bool				_isSigned;
		const int			_gradeForSigne;
		const int			_gradeForExecute;
};

