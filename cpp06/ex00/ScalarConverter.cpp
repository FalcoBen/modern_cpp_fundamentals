#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>     
#include <climits>
#include <cmath>
#include <cctype>
#include <iomanip>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
    static_cast<void>(src);
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

void api_invalid()
{
    std::cout << "char: impossible\n"
                  << "int: impossible\n"
                  << "float: impossible\n"
                  << "double: impossible\n";
}
void api_char(const std::string& input)
{

    char c = input[0];

    std::cout << "char: ";

    if (!std::isprint(static_cast<unsigned char>(c)))
        std::cout << "Non displayable";
    else
        std::cout << "'" << c << "'";

    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);

    std::cout << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}
void api_int(const std::string& input)
{
    long value = std::strtol(input.c_str(), NULL, 10);
    std::cout << "char: ";
    if (value < CHAR_MIN || value > CHAR_MAX)
        std::cout << "impossible";
    else if (!std::isprint(static_cast<unsigned char>(value)))
        std::cout << "Non displayable";
    else
        std::cout << "'" << static_cast<char>(value) << "'";
    std::cout << std::endl;

    std::cout << "int: ";
    if (value < INT_MIN || value > INT_MAX)
        std::cout << "impossible";
    else
        std::cout << static_cast<int>(value);
    std::cout << std::endl;

    double d = std::strtod(input.c_str(), NULL);
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void api_float(const std::string& input)
{
    float ff = std::strtof(input.c_str(), NULL);

    if (std::isnan(ff) || std::isinf(ff))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    std::cout << "char: ";
    if (ff < CHAR_MIN || ff > CHAR_MAX)
        std::cout << "impossible";
    else if (!std::isprint(static_cast<unsigned char>(ff)))
        std::cout << "Non displayable";
    else
        std::cout << "'" << static_cast<char>(ff) << "'";
    std::cout << std::endl;

    std::cout << "int: ";
    if (ff < INT_MIN || ff > INT_MAX)
        std::cout << "impossible";
    else
        std::cout << static_cast<int>(ff);
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "float: " << ff << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(ff) << std::endl;
}

void api_double(const std::string& input)
{
    double dd = std::strtod(input.c_str(), NULL);

    if (std::isnan(dd) || std::isinf(dd))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    std::cout << "char: ";
    if (dd < CHAR_MIN || dd > CHAR_MAX)
        std::cout << "impossible";
    else if (!std::isprint(static_cast<unsigned char>(dd)))
        std::cout << "Non displayable";
    else
        std::cout << "'" << static_cast<char>(dd) << "'";
    std::cout << std::endl;

    std::cout << "int: ";
    if (dd < INT_MIN || dd > INT_MAX)
        std::cout << "impossible";
    else
        std::cout << static_cast<int>(dd);
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "float: " << static_cast<float>(dd) << "f" << std::endl;
    std::cout << "double: " << dd << std::endl;
}

void api_special(const std::string& input)
{
    std::cout << "char: impossible\n"
                  << "int: impossible\n";
    if (input == "nanf" || input == "nan")
    {
        std::cout << "float: nanf\n"
                  << "double: nan\n";
    }
    else if (input == "+inff" || input == "+inf" || input == "inff" || input == "inf")
    {
        std::cout << "float: +inff\n"
                  << "double: +inf\n";
    }
    else
    {
        std::cout << "float: -inff\n"
                  << "double: -inf\n";
    }
    return;
}

void ScalarConverter::convert(const std::string& input)
{
    InputType state = pars_input(input);
    switch (state)
    {
        case Type_CHAR:
            api_char(input);
            break;
        case Type_INT:
            api_int(input);
            break;
        case Type_FLOAT:
            api_float(input);
            break;
        case Type_DOUBLE:
            api_double(input);
            break;
        case Type_SPECIAL:
            api_special(input);
            break;
        case Type_INVALID:
            api_invalid();
            break;
        default:
            std::cout << "its not handled" << std::endl;
            break;
    }
}