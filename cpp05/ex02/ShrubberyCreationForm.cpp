#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>
#include <fcntl.h>
ShrubberyCreationForm::ShrubberyCreationForm() :  AForm("ShrubberyCreationForm", 145, 137),  _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src), _target(src._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
    if(this != &src)
    {
        AForm::operator=(src);
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
std::string ShrubberyCreationForm::getTarget() const
{
    return _target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const 
{
    if(!getIsSigned())
        throw (AForm::FormNotSignedException());
    if(executor.getGrade() > getGradeToExecute())
        throw (AForm::GradeTooLowException());
    
    std::string file_name;
    file_name = _target + "_shrubbery";
    
    std::ofstream outfile;
    outfile.open(file_name.c_str());
    if(outfile.fail())
        throw (std::runtime_error("open_file failed"));
    
    outfile << "       _-_        \n"
               "    /~~   ~~\\    \n"
               " /~~     -l    ~~\\ \n"
               "{               }\n"
               " \\  _-     -_  / \n"
               "   ~  \\\\ //  ~   \n"
               "       | |        \n"
               "       | |        \n"
               "      // \\\\      \n"
               "-----------------\n" << std::endl;
    outfile.close();
}
