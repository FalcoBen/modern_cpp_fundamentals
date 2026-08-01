#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form Grade Too High !!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form Grade Too Low !!";
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
    
}
Form::GradeTooLowException::~GradeTooLowException() throw()
{

}


int Form::_checkGradeForm(int grade)
{
    if(grade > 150)
        throw (Form::GradeTooLowException());
    else if(grade < 1)
        throw (Form::GradeTooHighException());
    return grade;
}

Form::Form() : _name_form("default"), _is_signed(false), _grade_to_sign(2), _grade_to_execute(2) 
{
}

Form::Form(const std::string& name, int GradeToSign, int GradeToExecute) : _name_form(name), 
                _is_signed(false), _grade_to_sign(_checkGradeForm(GradeToSign)), _grade_to_execute(_checkGradeForm(GradeToExecute)) 
{
}

Form::Form(const Form& src) : _name_form(src._name_form), _is_signed(src._is_signed), 
                _grade_to_sign(src._grade_to_sign), _grade_to_execute(src._grade_to_execute) 
{
}

Form& Form::operator=(const Form& src)
{
    if(this != &src)
    {
        this->_is_signed = src._is_signed;
    }
    return (*this);
}

Form::~Form()
{
}

std::string  Form::getNameForm() const
{
    return _name_form;
}
bool Form::getIsSigned() const
{
    return _is_signed;
}
int  Form::getGradeToSign() const
{
    return _grade_to_sign;
}
int  Form::getGradeToExecute() const
{
    return _grade_to_execute;
}

void    Form::beSigned(const Bureaucrat& bureaucrat)
{
    if(bureaucrat.getGrade() > _grade_to_sign)
        throw (Form::GradeTooLowException());
    _is_signed = true;
}

std::ostream& operator<<(std::ostream& out, const Form& form_obj)
{
    std::string result; 
    if(form_obj.getIsSigned())
        result = "Yes";
    else
        result = "No";

    out << "<" << form_obj.getNameForm() << ">, " << "form grade to sign = " << form_obj.getGradeToSign() \
        <<   " form grade to execute = " << form_obj.getGradeToExecute() << " status " << result;
    return out;
}