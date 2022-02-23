#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form{
public:
	PresidentialPardonForm(std::string const target);
	PresidentialPardonForm(PresidentialPardonForm const & p);
	~PresidentialPardonForm();
	PresidentialPardonForm & operator=(PresidentialPardonForm const &p);
	std::string getTarget() const;
	virtual void execute(Bureaucrat const & bureaucrat);
private:
	std::string target;
	PresidentialPardonForm();
};


#endif