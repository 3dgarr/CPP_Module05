#pragma once

#include <iostream>

class Bureaucrat
{
	public:
		std::string		getName(void) const;
		int				getGrade(void) const;
		void			incrementGrade(void);
		void			decrementGrade(void);

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat&);
		Bureaucrat(const std::string, int);
		Bureaucrat&	operator=(const Bureaucrat&);
		~Bureaucrat();
	
	protected:
		const std::string	_name;
		int					_grade;//[1(Highest); 150(Lowest)]
		const int			MINGRADE;
		const int			MAXGRADE;
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat& b);

