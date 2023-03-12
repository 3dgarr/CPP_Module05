#pragma once

#include "./AForm.hpp"
#include <exception>
#include <string>
#include <ctime>
#include <cstdlib>
#include <unistd.h>

class RobotomyRequestForm :  public AForm
{
	public:
		void		execute(const Bureaucrat&) const;
		void		beSigned(const Bureaucrat&);
		std::string	getFormTarget(void) const;
		bool		getSignedFlag(void) const;
		int			getGradeForSigne(void) const;	
		int			getGradeForExecute(void) const;	
		
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm&);
		RobotomyRequestForm(const std::string);
		RobotomyRequestForm& operator=(const RobotomyRequestForm&);
		~RobotomyRequestForm();

	private:
		std::string			_target;
		bool				_isSigned;
		const int			_gradeForSigne;
		const int			_gradeForExecute;
};
std::ostream&	operator<<(std::ostream&, const RobotomyRequestForm&);

