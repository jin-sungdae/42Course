#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
	this->name = "noName";
	this->grade = 0;
	std::cout << "Bureaucrat construcotr called" << std::endl;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade){
	std::cout << "Bureaucrat name, grade constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & b){
	*this = b;
	std::cout << "Bureaucrat a little copy called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &b){
	this->name = b.getName();
	this->grade = b.getGrade();
	std::cout << "Bureaucrat deep copy called" << std::endl;
	return *this;
}

std::string Bureaucrat::getName() const{
	return this->name;
}

int Bureaucrat::getGrade() const{
	return this->grade;
}

void Bureaucrat::setName(std::string const name){
	this->name = name;
}

void Bureaucrat::setGrade(int const grade){
	this->grade = grade;
}

void Bureaucrat::increaseGrade(int grade){
	this->grade -= grade;
	checkGrade();
}

void Bureaucrat::decreaseGrade(int grade){
	this->grade += grade;
	checkGrade();
}

void Bureaucrat::checkGrade (){
	if (this->grade < Bureaucrat::highestGrade)
		throw Bureaucrat::GradeTooHightException();
	else if (this->grade > Bureaucrat::lowestGrade)
		throw Bureaucrat::GradeTooLowException();
}

std::ostream & operator <<(std::ostream & stream, Bureaucrat const & bureaucrat){
	stream << "bureaucrat Name = " << bureaucrat.getName() << " bureaucrat grade = " << bureaucrat.getGrade();
	return stream;
}