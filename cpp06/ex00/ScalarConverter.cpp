#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <iomanip>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
    (void) src;

}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src)
{
    (void) src;
    if(this != &src)
    {

    }
    return *this;
}

ScalarConverter::~ScalarConverter()
{
}

/*
• char
• int
• float
• double
*/

void ScalarConverter::convert(const std::string& input)
{
    
}



