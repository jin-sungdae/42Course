#include <fstream>
#include "ShrubbertCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("ShrubberyCreationForm", 145, 137), target(target){
	std::cout << "ShrubberyCreationForm Create Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), target(""){
	std::cout << "ShrubberyCreationForm default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & s):Form("ShrubberyCreationForm", 145,137), target(s.getTarget()){
	std::cout << "ShrubberyCreationForm a little Copy " << std::endl;
	*this = s;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & s){
	this->target = s.getTarget();
	std::cout << "ShrubberyCreationForm Deep Copy" << std::endl;
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const{
	return this->target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & bureaucrat){
	std::ofstream file;
	std::string fileName = this->target + "_shrubbery";

	this->checkExecuteGrade(bureaucrat);
	file.open(fileName.c_str(), std::ios::out);

	file <<      "."		<< std::endl;
	file <<   "__/\\__"		<< std::endl;
	file <<  "\\      /"	<< std::endl;
	file <<   "/.'o'.\\"	<< std::endl;
	file <<    ".o.'."		<< std::endl;
	file <<   ".'.'o'."		<< std::endl;
	file <<  "o'.o.'.o."	<< std::endl;
	file <<  ".'.o.'.'.o."	<< std::endl;
	file <<".o.'.o.'.o.'."	<< std::endl;
	file <<   "[_____]"		<< std::endl;
	file <<   "\\___/ "		<< std::endl;

}
