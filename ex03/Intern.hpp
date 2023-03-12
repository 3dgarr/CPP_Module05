#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "./AForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./ShrubberyCreationForm.hpp"

class Intern
{
	public:
		AForm*	makeForm(const std::string formName, const std::string target) const;

	public:
		Intern();
		Intern(const Intern&);
		Intern& operator=(const Intern&);
		~Intern();

	private:
		AForm*	makeShrubberyCreationForm(const std::string) const;
		AForm*	makePresidentialPardonForm(const std::string) const;
		AForm*	makeRobotomyRequestForm(const std::string) const;
		int		getFunctionIndex(const std::string fName) const;
	
	public:
		class	UndefinedFunctionName: public std::exception
		{
			public:
				const char *what() const throw();
		};
};

typedef	AForm*(Intern::*FormMakers)(std::string) const;
