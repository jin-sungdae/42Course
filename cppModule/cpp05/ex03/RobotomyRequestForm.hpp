#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form{
public:
	RobotomyRequestForm(std::string const target);
	RobotomyRequestForm(RobotomyRequestForm const & r);
	~RobotomyRequestForm();
	RobotomyRequestForm &operator=(RobotomyRequestForm const & r);
	std::string getTarget() const;
	virtual void execute(Bureaucrat const &bureaucrat);
private:
	std::string target;
	RobotomyRequestForm();
};

#endif