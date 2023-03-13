#pragma once

#include <iostream>
#include <exception>
#include <string>
#include "./AForm.hpp"

class AForm;

class Bureaucrat
{
	public:
		std::string		getName(void) const;
		int				getGrade(void) const;
		void			incrementGrade(void);
		void			decrementGrade(void);
		void			signForm(AForm&) const;
		void			executeForm(const AForm&) const;
		
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat&);
		Bureaucrat(const std::string, int);
		Bureaucrat&	operator=(const Bureaucrat&);
		~Bureaucrat();
	
	protected:
		const std::string	_name;
		int					_grade;
		const int			MINGRADE;
		const int			MAXGRADE;
	
	public:
		class	GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream &, const Bureaucrat&);

