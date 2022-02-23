#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():Form("PresidentialPardonForm", 25, 5), target(""){
	//std::cout << "PresidentialPardonForm default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target):Form("PresidentialPardonForm", 25, 5), target(target){
	//std::cout << "PresidentialPardonForm Constructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & p):Form("PresidentialPardonForm", 25, 5), target(p.getTarget()){
	//std::cout << "PresidentialPardonForm a little Copy" << std::endl;
	*this = p;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	//std::cout << "PresidentialPardonForm Destructor Called" << std::endl;
}

PresidentialPardonForm &  PresidentialPardonForm::operator=(PresidentialPardonForm const &p){
	this->target = p.getTarget();
	//std::cout << "PresidentialPardonForm Deep Copy" << std::endl;
	return *this;
}

std::string PresidentialPardonForm::getTarget() const{
	return this->target;
}

void PresidentialPardonForm::execute(Bureaucrat const & bureaucrat){
	this->checkExecuteGrade(bureaucrat);
	std::cout << this->target << "has been pardoned by Zafod Beeblebrox." << std::endl;
}