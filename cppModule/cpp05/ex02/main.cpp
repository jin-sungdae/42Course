#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubbertCreationForm.hpp"

#define null NULL;

int main(){
	Form *form = null;
	Bureaucrat jin("jin", 50);
	Bureaucrat jon("jon", 70);
	Bureaucrat jan("jan", 90);
	Bureaucrat jun("jun", 120);
	
	try{
		form = new PresidentialPardonForm("28Z");
		form->execute(jin);
		delete form;
		form = null;
	}catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try{
		form = new PresidentialPardonForm("Target2");
		form->signCheckBool(jin);
		form->execute(jin);
		delete form;
		form = null;
	}catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try{
		form = new RobotomyRequestForm("Target3");
		form->signCheckBool(jin);
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
		form = new ShrubberyCreationForm("Target4");
		form->signCheckBool(jin);
		form->execute(jun);
		form->execute(jan);
		delete form;
		form = null;
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	return 0;
}