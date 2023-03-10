#pragma once

#include <iostream>
#include <exception>
#include "./Bureaucrat.hpp"

class Form
{
	public:
		void		beSigned(Bureaucrat&);
		std::string	getFormName(void) const;
		bool		getSignedFlag(void) const;
		int			getGradeForSigne(void) const;	
		int			getGradeForExecute(void) const;	
		

	public:
		Form();
		Form(const Form&);
		Form(const std::string, int, int);
		Form& operator=(const Form&);
		~Form();

	public:
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();	
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

	
	private:
		const std::string	_formName;
		bool				_isSigned;
		const int			_gradeForSigne;
		const int			_gradeForExecute;			

};

std::ostream&	operator<<(std::ostream&, const Form&);
