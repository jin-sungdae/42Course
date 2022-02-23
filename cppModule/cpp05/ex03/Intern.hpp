#ifndef INTERN_HPP
#define INTERN_HPP


#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern{
public:
    Intern();
    ~Intern();
    Intern(Intern const &i);
    Intern & operator=(Intern const & i);
    Form *makeForm(const std::string &formName, const std::string &target) const;

private:
    typedef struct s_formList{
        std::string formName;
        Form    *formType;
    }           t_formList;
};

std::ostream &operator<<(std::ostream &stream, Intern const & intern);

#endif