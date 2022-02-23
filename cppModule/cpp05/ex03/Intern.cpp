#include "Intern.hpp"

Intern::Intern(){
    //std::cout << "Intern default Constructor called" << std::endl;
}

Intern::~Intern(){
    //std::cout << "Intern destructor called" << std::endl;
	
}

Intern::Intern(Intern const & i){
    *this = i;
    //std::cout << "Intern a little Copy" << std::endl;
}

Intern & Intern::operator=(Intern const & i){
    (void)i;
    //std::cout << "Intern Deep Copy" << std::endl;
    return *this;
}

Form	*Intern::makeForm(const std::string &formName, const std::string &target) const{
	t_formList formList[] = {
		{ "presidential pardon", new PresidentialPardonForm(target) },
		{ "robotomy request", new RobotomyRequestForm(target) },
		{ "shrubbery creation", new ShrubberyCreationForm(target) },
		{ "", NULL }
	};
	Form	*form = NULL;

	for (int i = 0; formList[i].formType != NULL; i++){
		if (formList[i].formName == formName)
			form = formList[i].formType;
		else
			delete formList[i].formType;
	}
	if (form == NULL)
		std::cout << "Intern did not find the form " << formName << std::endl;
	else
		std::cout << "Intern creates " << formName << std::endl;
	return form;
}

std::ostream & operator<<(std::ostream &stream, Intern const & intern){
    (void)intern;
    stream << "Intern" << std::endl;
    return stream;
}