#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
	
public:
	Form(const std::string name, int signGrade, int executeGrade);
	Form(const Form &f);
	virtual ~Form(void);
	Form & operator=(Form const & f);
	std::string getName() const;
	int	getSignGrade() const;
	int getExecuteGrade() const;
	bool getSignCheck() const;
	void checkGrade() const;
	void checkExecuteGrade(const Bureaucrat &bureaucrat) const;
	bool signCheckBool(const Bureaucrat & bureaucrat);
	virtual void execute(Bureaucrat const & bureaucrat) = 0;

private:
	Form();
	std::string name;
	bool signCheck;
	const int signGrade;
	const int executeGrade;
	static const int lowestGrade = 150;
	static const int highestGrade = 1;

public:
	class GradeTooHightException : public std::exception{
	public:
		virtual const char *what() const throw(){
			return "Grade Too High";
		}
	};
	
	class GradeTooLowException : public std::exception{
	public:
		virtual const char *what() const throw(){
			return "Grade Too Low";
		}
	};

	class CantExecuteForm : public std::exception{
	public:
		virtual const char *what() const throw(){
			return "Can't execute";
		}
	};
};
std::ostream & operator<<(std::ostream & stream, Form const & form);


#endif