#pragma once

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat
{
	public:
		std::string		getName(void) const;
		int				getGrade(void) const;
		void			incrementGrade(void);
		void			decrementGrade(void);
		void			signForm(const std::string&, int) const;

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
				virtual	const char *what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual	const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream &, const Bureaucrat&);

