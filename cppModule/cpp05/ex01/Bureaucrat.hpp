#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat{
public:
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(Bureaucrat const & b);
	Bureaucrat & operator=(Bureaucrat const & b);
	std::string getName() const;
	int getGrade() const;
	void setName(std::string const name);
	void setGrade(int const grade);
	void increaseGrade(int grade);
	void decreaseGrade(int grade);
	bool executeForm(Form & f) const;
	bool signForm(Form &f) const;

private:
	std::string name;
	int grade;
	static const int lowestGrade = 150;
	static const int highestGrade = 1;
	void checkGrade();
	Bureaucrat();

public:
	class GradeTooHightException : public std::exception{
	public:
		virtual const char* what() const throw(){
			return ("Grade Too High");
		}
	};
	class GradeTooLowException : public std::exception{
	public:
		virtual const char* what() const throw(){
			return ("Grade Too Low");
		}
	};
	
};
std::ostream & operator<<(std::ostream & stream, Bureaucrat const & bureaucrat);
#endif