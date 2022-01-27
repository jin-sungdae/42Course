#include "Form.hpp"

Form::Form() : name("no_name"), signCheck(false), 
				signGrade(Form::lowestGrade), executeGrade(Form::highestGrade){
	std::cout << "Form default Constructor called" << std::endl;
}

Form::Form(std::string name,  int signGrade, int executeGrade)
		: name(name), signGrade(signGrade), executeGrade(executeGrade){
	this->checkGrade();
	std::cout << "Form 3 param Constructor called" << std::endl;
}

Form::Form(Form const & f): 
name(f.name), signCheck(f.signCheck), signGrade(f.signGrade), executeGrade(f.executeGrade){
	std::cout << "Form a little Copy called" << std::endl;
	*this = f;
}

Form & Form::operator=(Form const & f){
	this->signCheck = f.signCheck;
	std::cout << "Form deep Copy called" << std::endl;
	return *this;
}

Form::~Form(){
	std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const{
	return this->name;
}

int	Form::getSignGrade() const{
	return this->signGrade;
}

int Form::getExecuteGrade() const{
	return this->executeGrade;
}

bool Form::getSignCheck() const{
	return this->signCheck;
}

void Form::checkGrade() const{
	if (this->executeGrade < Form::highestGrade && this->signGrade < Form::highestGrade)
		throw Form::GradeTooHightException();
	if (this->executeGrade > Form:: lowestGrade && this->signGrade < Form::lowestGrade)
		throw Form::GradeTooLowException();
}

void Form::checkExecuteGrade(const Bureaucrat &bureaucrat) const{
	if (this->signCheck || bureaucrat.getGrade() > this->executeGrade)
		throw Form::CantExecuteForm();
}

bool Form::signCheckBool(const Bureaucrat & bureaucrat){
	if (bureaucrat.getGrade() < this->signGrade){
		this->signCheck = true;
		return true;
	}
	else{
		this->signCheck = false;
		return false;
	}
}

std::ostream & operator<<(std::ostream & stream, Form const & form){
	stream << "Form name = " << form.getName() << " Form signGrade = " << form.getSignGrade()
	<< " Form executeGrade = " << form.getExecuteGrade() << " Form signCheck = " << form.getSignCheck();
	return stream;
}