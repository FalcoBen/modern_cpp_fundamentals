#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cerr << "Error, only one argument" << std::endl;
        return 1;
    }
    try
    {
        ScalarConverter::convert(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}