#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define null NULL;

int main(){
	Form *form = null;
	Bureaucrat jin("jin", 1);
	Bureaucrat jon("jon", 3);
	Bureaucrat jan("jan", 90);
	Bureaucrat jun("jun", 2);
	
	try{
		form = new PresidentialPardonForm("Target1");
		std::cout << form->getTarget() << " " << form->getSignGrade() << " " << form->getExecuteGrade() << std::endl;
		form->beSigned(jin);
		form->execute(jin);
		delete form;
		form = null;
	}catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try{
		form = new PresidentialPardonForm("Target2");
		form->beSigned(jan);
		form->execute(jan);
		delete form;
		form = null;
	}catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try{
		form = new RobotomyRequestForm("Target3");
		form->beSigned(jon);
		form->execute(jon);
		form->execute(jon);
		form->execute(jon);
		form->execute(jon);
		form->execute(jon);
		form->execute(jon);
		form->execute(jon);
		form->execute(jon);
		form->execute(jon);
		form->execute(jon);
		delete form;
		form = null;
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;


	try{
		form = new RobotomyRequestForm("Target3");
		form->execute(jan);
		form->execute(jan);
		form->execute(jan);
		form->execute(jan);
		form->execute(jan);
		form->execute(jan);
		form->execute(jan);
		form->execute(jan);
		form->execute(jan);
		form->execute(jan);
		delete form;
		form = null;
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try{
		form = new ShrubberyCreationForm("Target4");
		form->beSigned(jun);
		form->execute(jun);
		delete form;
		form = null;
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	return 0;
}