#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const target):
	Form("RobotomyRequestForm", 72, 45), target(target){
	std::cout << "RobotomyRequestForm Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm():
	Form("RobotomyRequestForm", 72, 45), target(""){
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & r) :
	Form("RobotomyRequestForm", 72, 45),target(r.getTarget()){
	std::cout << "RobotomyRequestForm a little Copy" << std::endl;
	*this = r;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const &r){
	this->target = r.getTarget();
	std::cout << "RobotomyRequestForm deep Copy" << std::endl;
	return *this;
}

std::string RobotomyRequestForm::getTarget() const{
	return this->target;
}

void RobotomyRequestForm::execute(Bureaucrat const & bureaucrat){
	this->checkExecuteGrade(bureaucrat);
	std::cout << "makes some drilling noise" << std::endl;
	if (std::rand() % 2){
		std::cout << this->target << "has been suceessfull " << std::endl;
	}
	else
		std::cout << this->target << "fail" << std::endl;
}

