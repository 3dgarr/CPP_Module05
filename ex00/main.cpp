#include "./Bureaucrat.hpp"

int main()
{

	Bureaucrat	a;
	Bureaucrat	b("Davo", 15);

	// std::cout << a.getName() << " " << a.getGrade() << std::endl;
	std::cout << a << std::endl;
	a = b;
	std::cout << a << std::endl;

	// std::cout << a.getName() << " " << a.getGrade() << std::endl;
}