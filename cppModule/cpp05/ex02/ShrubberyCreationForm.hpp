#ifndef SHRUBBERYCREATIONALFORM_HPP
#define SHRUBBERYCREATIONALFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Form{
public:
	ShrubberyCreationForm(std::string const target);
	ShrubberyCreationForm(ShrubberyCreationForm const & s);
	~ShrubberyCreationForm();
	ShrubberyCreationForm & operator=(ShrubberyCreationForm const & s);
	std::string getTarget() const;
	virtual void execute(Bureaucrat const & bureaucrat);
private:
	std::string target;
	ShrubberyCreationForm();
};

#endif