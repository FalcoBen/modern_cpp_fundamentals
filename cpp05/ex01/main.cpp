#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Form default_f;
        std::cout << default_f << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Form contract("test1", 10 , 5);
        std::cout << contract << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Form invalid_high("test2_hight", 0 , 5);
        std::cout << invalid_high << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Form invalid_low("test3_low", 1 , 151);
        std::cout << invalid_low << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat prof("test4", 10);
        Form paper("blank_paper", 10, 10);
        prof.signForm(paper);
        std::cout << paper << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat student("student", 100);
        Form advanced("advanced_File", 20, 5);
        std::cout << advanced << std::endl;
        student.signForm(advanced);
        std::cout << advanced << std::endl;

    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

}
