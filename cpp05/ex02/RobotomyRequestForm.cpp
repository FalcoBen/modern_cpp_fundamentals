#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) :  AForm(src), _target(src._target)
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
    if(this != &src)
    {
        this->_target = src._target;
        AForm::operator=(src);
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if(!getIsSigned())
        throw (AForm::FormNotSignedException());
    if(executor.getGrade() > getGradeToExecute())
        throw (AForm::GradeTooLowException());
    std::cout << "* drilling noises *" << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << _target << " has been robotomized successfully." << std::endl;
    else 
        std::cout << "Robotomy failed for " << _target << "." << std::endl;
}
