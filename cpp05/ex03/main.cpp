#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>
#include "Intern.hpp"

int main()
{
    try
    {
        std::srand(std::time(NULL));

        // std::cout << "========== INTERN CREATES ROBOTOMY ==========\n";
        // {
        //     Intern intern;
        //     Bureaucrat boss("Boss", 149);

        //     AForm* form = intern.makeForm("robotomy request", "Bender");

        //     if (form)
        //     {
        //         std::cout << *form << std::endl;

        //         boss.signForm(*form);
        //         std::cout << "-----------------------------" << std::endl;
        //         boss.executeForm(*form);
        //         delete form;
        //     }
        // }

        std::cout << "\n========== INTERN CREATES SHRUBBERY ==========\n";
        {
            Intern intern;
            Bureaucrat gardener("Gardener", 1);

            AForm* form = intern.makeForm("shrubbery creation", "home");

            if (form)
            {
                std::cout << *form << std::endl;

                gardener.signForm(*form);
                gardener.executeForm(*form);

                delete form;
            }
        }

        std::cout << "\n========== INTERN CREATES PRESIDENTIAL ==========\n";
        {
            Intern intern;
            Bureaucrat president("President", 1);

            AForm* form = intern.makeForm("presidential pardon", "Arthur Dent");

            if (form)
            {
                std::cout << *form << std::endl;

                president.signForm(*form);
                president.executeForm(*form);

                delete form;
            }
        }

        std::cout << "\n========== UNKNOWN FORM ==========\n";
        {
            Intern intern;

            AForm* form = intern.makeForm("coffee request", "kitchen");

            if (form)
                delete form;
        }

        std::cout << "\n========== EXECUTION GRADE TOO LOW ==========\n";
        {
            Intern intern;

            Bureaucrat signer("Signer", 1);
            Bureaucrat executor("Executor", 50);

            AForm* form = intern.makeForm("robotomy request", "Marvin");

            if (form)
            {
                signer.signForm(*form);
                executor.executeForm(*form);

                delete form;
            }
        }

        std::cout << "\n========== SIGN GRADE TOO LOW ==========\n";
        {
            Intern intern;

            Bureaucrat low("Low", 150);

            AForm* form = intern.makeForm("presidential pardon", "Ford");

            if (form)
            {
                low.signForm(*form);
                delete form;
            }
        }

        std::cout << "\n========== EXECUTE WITHOUT SIGNING ==========\n";
        {
            Intern intern;

            Bureaucrat boss("Boss", 1);

            AForm* form = intern.makeForm("shrubbery creation", "garden");

            if (form)
            {
                boss.executeForm(*form);
                delete form;
            }
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}