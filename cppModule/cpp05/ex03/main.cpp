#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void){
	Intern		intern;
	Bureaucrat	jin("jin", 3);
	Form		*form;

	form = intern.makeForm("this one doesn't exist", "jun");
	if (form)
		delete form;
	form = intern.makeForm("presidential pardon", "jan");
	form->beSigned(jin);
	form->execute(jin);
	if (form)
		delete form;
	form = intern.makeForm("shrubbery creation", "jon");
	form->beSigned(jin);
	form->execute(jin);
	if (form)
		delete form;
	form = intern.makeForm("robotomy request", "jing");
	form->beSigned(jin);
	form->execute(jin);
	if (form)
		delete form;
}