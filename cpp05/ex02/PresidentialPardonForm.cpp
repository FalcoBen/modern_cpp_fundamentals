#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>


PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src), _target(src._target)
{
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
    if(this != &src)
    {
        AForm::operator=(src);
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if(!getIsSigned())
        throw (AForm::FormNotSignedException());
    if(executor.getGrade() > getGradeToExecute())
        throw (AForm::GradeTooLowException());
    std::cout << "<" << _target << "> has been pardoned by Zaphod Beeblebrox." << std::endl;
}
