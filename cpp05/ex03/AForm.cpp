#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm Grade Too High !!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm Grade Too Low !!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Cannot execute because the form is not signed !!";
}

int AForm::checkGradeForm(int grade)
{
    if(grade > 150)
        throw (AForm::GradeTooLowException());
    else if(grade < 1)
        throw (AForm::GradeTooHighException());
    return grade;
}

AForm::GradeTooHighException::~GradeTooHighException() throw()
{
}

AForm::GradeTooLowException::~GradeTooLowException() throw()
{
}

AForm::FormNotSignedException::~FormNotSignedException() throw()
{
}

AForm::AForm() : _name_form("default"), _is_signed(false), _grade_to_sign(2), _grade_to_execute(2) 
{
}

AForm::AForm(const std::string& name, int GradeToSign, int GradeToExecute) : _name_form(name), 
                _is_signed(false), _grade_to_sign(checkGradeForm(GradeToSign)), _grade_to_execute(checkGradeForm(GradeToExecute)) 
{
}

AForm::AForm(const AForm& src) : _name_form(src._name_form), _is_signed(src._is_signed), 
                _grade_to_sign(src._grade_to_sign), _grade_to_execute(src._grade_to_execute) 
{
}

AForm& AForm::operator=(const AForm& src)
{
    if(this != &src)
    {
        this->_is_signed = src._is_signed;
    }
    return (*this);
}

AForm::~AForm()
{
}

std::string  AForm::getNameForm() const
{
    return _name_form;
}
bool AForm::getIsSigned() const
{
    return _is_signed;
}
int  AForm::getGradeToSign() const
{
    return _grade_to_sign;
}
int  AForm::getGradeToExecute() const
{
    return _grade_to_execute;
}

void    AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if(bureaucrat.getGrade() > _grade_to_sign)
        throw (AForm::GradeTooLowException());
    _is_signed = true;
}


std::ostream& operator<<(std::ostream& out, const AForm& Aform_obj)
{
    std::string result; 
    if(Aform_obj.getIsSigned())
        result = "Yes";
    else
        result = "No";

    out << "<" << Aform_obj.getNameForm() << ">, " << "Aform grade to sign = " << Aform_obj.getGradeToSign() \
        <<   " Aform grade to execute = " << Aform_obj.getGradeToExecute() << " status " << result << std::endl;
    return out;
}
