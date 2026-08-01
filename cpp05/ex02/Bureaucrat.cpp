#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <string>
#include <iostream>

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat Grade too High !!";
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat Grade too Low !!";
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
}

int Bureaucrat::_CheckGrade(int grade)
{
    if(grade < 1)
        throw (Bureaucrat::GradeTooHighException());
    else if(grade > 150)
        throw (Bureaucrat::GradeTooLowException());
    return grade;
}


Bureaucrat::Bureaucrat() : _name("default"), _grade(1)
{
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(_CheckGrade(grade))
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name)
{
    this->_grade = src._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
    if(this != &src)
    {
        this->_grade = src._grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName() const 
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void    Bureaucrat::increment_grade()
{
    _CheckGrade(_grade - 1);
    _grade--;
}
void    Bureaucrat::decrement_grade()
{
    _CheckGrade(_grade + 1);
    _grade++;
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat& bureaucrat)
{
    out << "<" << bureaucrat.getName() << ">, " << "bureaucrat grade <" << bureaucrat.getGrade() << ">";
    return out;
}

void Bureaucrat::signForm(AForm& form_obj)
{
    try
    {
        form_obj.beSigned(*this);
        std::cout << getName() << " signed " << form_obj.getNameForm() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << getName() << " couldn't sign " << form_obj.getNameForm()
                   << " because " << e.what() << "." << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
        form.execute(*this);
        std::cout << _name << " executed " << form.getNameForm() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << _name << " couldn't execute " << form.getNameForm() << " because " << e.what() << std::endl;
    }
    
}