#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat default_b;
        std::cout << default_b << std::endl;
        default_b.decrement_grade();
        std::cout << default_b << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat boss("test1", 2);
        std::cout << boss << std::endl;
        boss.increment_grade();
        std::cout << boss << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat student("test2", 149);
        std::cout << student << std::endl;
        student.decrement_grade();
        std::cout << student << std::endl;
        student.decrement_grade();
        std::cout << student << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat fugitive_0("fail_high", 0);
        std::cout << fugitive_0 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat fugitive_151("fail_low", 151);
        std::cout << fugitive_151 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
















































































// int main()
// {
//     std::cout << "========== VALID CONSTRUCTION ==========\n";
//     try
//     {
//         Bureaucrat a("Alice", 1);
//         Bureaucrat b("Bob", 75);
//         Bureaucrat c("Charlie", 150);

//         std::cout << a << std::endl;
//         std::cout << b << std::endl;
//         std::cout << c << std::endl;
//     }
//     catch (const std::exception& e)
//     {
//         std::cerr << e.what() << std::endl;
//     }

//     std::cout << "\n========== INVALID CONSTRUCTION ==========\n";

//     try
//     {
//         Bureaucrat high("TooHigh", 0);
//     }
//     catch (const std::exception& e)
//     {
//         std::cerr << e.what() << std::endl;
//     }

//     try
//     {
//         Bureaucrat low("TooLow", 151);
//     }
//     catch (const std::exception& e)
//     {
//         std::cerr << e.what() << std::endl;
//     }

//     std::cout << "\n========== INCREMENT ==========\n";

//     try
//     {
//         Bureaucrat chief("Chief", 2);

//         std::cout << chief << std::endl;

//         chief.increment_grade();
//         std::cout << chief << std::endl;

//         chief.increment_grade();
//         std::cout << chief << std::endl;
//     }
//     catch (const std::exception& e)
//     {
//         std::cerr << e.what() << std::endl;
//     }

//     std::cout << "\n========== DECREMENT ==========\n";

//     try
//     {
//         Bureaucrat intern("Intern", 149);

//         std::cout << intern << std::endl;

//         intern.decrement_grade();
//         std::cout << intern << std::endl;

//         intern.decrement_grade();  // should throw
//         std::cout << intern << std::endl;
//     }
//     catch (const std::exception& e)
//     {
//         std::cerr << e.what() << std::endl;
//     }

//     return 0;
// }