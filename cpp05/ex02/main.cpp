#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
    std::srand(std::time(NULL));
    std::cout << "=====================ShrubberyCreationForm=======================" << std::endl;
    try
    {
        Bureaucrat owner("fahd", 136);
        ShrubberyCreationForm tree("home");
        owner.signForm(tree);
        std::cout << tree << std::endl;
        tree.execute(owner);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    std::cout << "=====================PresidentialPardonForm=======================" << std::endl;
    try
    {
        Bureaucrat director("CEO", 4);
        PresidentialPardonForm pardon("worker");
        director.signForm(pardon);
        std::cout << pardon << std::endl;
        pardon.execute(director);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    std::cout << "=====================RobotomyRequestForm.hpp=======================" << std::endl;
    try
    {
        Bureaucrat director("robot", 4);
        RobotomyRequestForm form_obj("form_robot");
        director.signForm(form_obj);
        std::cout << form_obj << std::endl;
        form_obj.execute(director);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }

    

    return 0;
}


// int main()
// {
//     // try
//     // {
//         std::srand(std::time(NULL));
//     try
//     {
//         Bureaucrat me("booss", 1);
//         ShrubberyCreationForm r("tettsttst");
//         me.signForm(r);
//         // me.executeForm(r);
//         // me.executeForm(r);
//         r.execute(me);
//         // me.executeForm(r);
//         // std::cout << r << std::endl;

//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
    
//     //     std::cout << "========== SHRUBBERY ==========" << std::endl;

//     //     // Bureaucrat with grade 137
//     //     // ShrubberyCreationForm("home")
//     //     Bureaucrat B1("buureacrat1", 137);
//     //     ShrubberyCreationForm shform("home");
//     //     try
//     //     {
//     //         shform.execute(B1);
//     //     }
//     //     catch(const std::exception& e)
//     //     {
//     //         std::cerr << e.what() << '\n';
//     //     }
        
//     //     // Try executing before signing (should fail)
//     //     B1.signForm(shform);
//     //     shform.execute(B1);
//     //     // Sign the form

//     //     // Execute the form (should create home_shrubbery)
//     //     std::cout << "inspect this file " <<  shform.getTarget() << " in the current directory to check content" << std::endl;
//     //     // Print a message telling the user to inspect the generated file.


//     //     std::cout << "\n========== ROBOTOMY ==========" << std::endl;

//     //     // Bureaucrat with grade 1
//     //     // RobotomyRequestForm("Bender")
//         // try
//         // {
//         //     Bureaucrat director("superior", 1);
//         //     RobotomyRequestForm robot_form("Bender");
            
//         //     director.signForm(robot_form);
//         //     robot_form.execute(director);
//         //     // robot_form.execute(director);
//         //     // robot_form.execute(director);
//         //     // robot_form.execute(director);
//         //     // robot_form.execute(director);
//         // }
//         // catch(const std::exception& e)
//         // {
//         //     std::cerr << e.what() << '\n';
//         // }
        
//     //     // Sign it

//     //     // Execute it several times (5 or 6)
//     //     // You should observe both success and failure.


//     //     std::cout << "\n========== PRESIDENTIAL PARDON ==========" << std::endl;

//     //     try
//     //     {
//     //         Bureaucrat king("king", 1);
//     //         PresidentialPardonForm fish("Arthur Dent");
//     //         king.signForm(fish);
//     //         fish.execute(king);            
//     //     }
//     //     catch(const std::exception& e)
//     //     {
//     //         std::cerr << e.what() << '\n';
//     //     }
        
//     //     // Bureaucrat with grade 1
//     //     // PresidentialPardonForm("Arthur Dent")

//     //     // Sign it

//     //     // Execute it


//     //     std::cout << "\n========== EXECUTION GRADE TOO LOW ==========" << std::endl;
//     //     try
//     //     {
//     //         Bureaucrat original("Bureaucrat", 50);
//     //         Bureaucrat another("imposter", 50);
//     //         RobotomyRequestForm robot_form("Marvin");
//     //         another.signForm(robot_form);
//     //         robot_form.execute(original);
//     //     }
//     //     catch(const std::exception& e)
//     //     {
//     //         std::cerr << e.what() << '\n';
//     //     }
        
//     //     // Bureaucrat with grade 50
//     //     // RobotomyRequestForm("Marvin")

//     //     // Sign with another bureaucrat if needed

//     //     // Execute with grade 50
//     //     // Should throw GradeTooLowException


//     //     std::cout << "\n========== SIGN GRADE TOO LOW ==========" << std::endl;

//     //     // Bureaucrat grade 150
//     //     // PresidentialPardonForm("Ford")

//     //     // Attempt to sign
//     //     // Should throw GradeTooLowException
//     //     try
//     //     {
//     //         Bureaucrat original("Bureaucrat", 150);
//     //         PresidentialPardonForm preform("Ford");
//     //         original.signForm(preform);
//     //         preform.execute(original);
//     //     }
//     //     catch(const std::exception& e)
//     //     {
//     //         std::cerr << e.what() << '\n';
//     //     }
        

//     //     std::cout << "\n========== INVALID FORM ==========" << std::endl;

//     //     // Try constructing a form with
//     //     // grade 0
//     //     // grade 151
//     //     // Both should throw.
//     // }
//     // catch (const std::exception& e)
//     // {
//     //     std::cerr << e.what() << std::endl;
//     // }
//     // try
//     // {
//     //     Bureaucrat bob("Bob", 1);
    
//     //     RobotomyRequestForm r("Bender");
//     //     // bob.signForm(r);
//     //     // r.execute(bob);
//     //     AForm* ptr = &r;
    
//     //     ptr->execute(bob);
//     // }
//     // catch(const std::exception& e)
//     // {
//     //     std::cerr << e.what() << '\n';
//     // }
    
// }