#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));
    std::cout << "test of ShrubberyCreationForm" << std::endl;
    try
    {
        Bureaucrat owner("fahd", 136);
        ShrubberyCreationForm tree("home");
        owner.signForm(tree);
        std::cout << tree << std::endl;
        owner.executeForm(tree);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    std::cout << "test of PresidentialPardonForm" << std::endl;
    try
    {
        Bureaucrat director("CEO", 4);
        PresidentialPardonForm pardon("worker");
        director.signForm(pardon);
        std::cout << pardon << std::endl;
        director.executeForm(pardon);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    std::cout << "test of RobotomyRequestForm" << std::endl;
    try
    {
        Bureaucrat director("robot", 4);
        RobotomyRequestForm form_obj("form_robot");
        director.signForm(form_obj);
        std::cout << form_obj << std::endl;
        director.executeForm(form_obj);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    std::cout << "test of failure case" << std::endl;
    try
    {
        Bureaucrat low_grade("sub_employe", 140);
        ShrubberyCreationForm form_obj("shrub1");

        low_grade.executeForm(form_obj);
        low_grade.signForm(form_obj);
        low_grade.executeForm(form_obj); 
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
