#pragma once

#include <iostream>
#include <exception>
#include "./Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		virtual void		execute(const Bureaucrat&) const = 0;
		virtual void		beSigned(const Bureaucrat&);
		virtual std::string	getFormName(void) const;
		virtual bool		getSignedFlag(void) const;
		virtual int			getGradeForSigne(void) const;	
		virtual int			getGradeForExecute(void) const;	
		
	public:
		AForm();
		AForm(const AForm&);
		AForm(std::string);
		AForm(const std::string, int, int);
		AForm& operator=(const AForm&);
		virtual	~AForm();

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
		class	IsAlreadySigned: public std::exception
		{
			public:
				const char *what() const throw();
		};
		class	FormIsNotSigned: public std::exception
		{
			public:
				const char *what() const throw();
		};
		class	ExecutionFailed: public std::exception
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

// std::ostream&	operator<<(std::ostream&, const AForm&);
