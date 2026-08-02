#include "Intern.hpp"
#include <iostream>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& src)
{
    (void)src;
}

Intern& Intern::operator=(const Intern& src)
{
    (void)src;
    if(this != &src)
    {

    }
    return (*this);
}

Intern::~Intern()
{

}

AForm* Intern::makeForm(const std::string& name_of_form, const std::string& target_form)
{
    const std::string forms[3] = {
        "robotomy request",
        "shrubbery creation",
        "presidential pardon"
    };
    AForm* (Intern::*creator[3])(const std::string&) = {
        &Intern::_create_robotomy,
        &Intern::_create_shrubbery,
        &Intern::_create_presidential
    };
    for(int i = 0; i < 3; i++)
    {
        if(forms[i] == name_of_form)
            return (this->*creator[i])(target_form);
    }
    std::cout << "Intern cannot create this form " << target_form << " due to invalid name of form [" << name_of_form + "]" << std::endl;
    return NULL;
}

AForm* Intern::_create_robotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}
AForm* Intern::_create_shrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);   
}
AForm* Intern::_create_presidential(const std::string& target)
{
    return new PresidentialPardonForm(target);
}


