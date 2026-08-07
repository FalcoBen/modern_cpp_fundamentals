#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>     
#include <cerrno>
#include <climits>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <limits>
ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
    // (void) src;// need to check agains the subject i think its  says use one type of casting 
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

enum InputType {
    Type_CHAR,
    Type_INT,
    Type_FLOAT,
    Type_DOUBLE,
    Type_SPECIAL,
    Type_INVALID 
};

bool is_it_char(const std::string& str)
{
    if (str.length() == 1 && !std::isdigit(static_cast<unsigned char>(str[0])))
        return true;
    return false;
}

bool is_it_int(const std::string& str)
{
    if (str.empty())
        return false;

    size_t i = 0;
    if (str[i] == '+' || str[i] == '-')
        ++i;

    if (i == str.size())
        return false;

    for (; i < str.size(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            return false;
    }
    return true;
}

bool is_it_float(const std::string& str)
{
    if (str.empty() || (str[str.size() - 1] != 'f' && str[str.size() - 1] != 'F'))
        return false;

    size_t len = str.size() - 1;
    if (len == 0)
        return false;

    int dot = 0;
    size_t i = 0;
    if (str[i] == '+' || str[i] == '-')
        ++i;

    bool has_digit = false;
    for (; i < len; ++i)
    {
        if (str[i] == '.')
        {
            ++dot;
            if (dot > 1)
                return false;
        }
        else if (std::isdigit(static_cast<unsigned char>(str[i])))
        {
            has_digit = true;
        }
        else
            return false;
    }
    return has_digit && (dot <= 1);
}

bool is_it_double(const std::string& str)
{
    if (str.empty())
        return false;

    size_t i = 0;
    int dot = 0;

    if (str[i] == '+' || str[i] == '-')
        ++i;

    bool has_digit = false;
    for (; i < str.size(); ++i)
    {
        if (str[i] == '.')
        {
            ++dot;
            if (dot > 1)
                return false;
        }
        else if (std::isdigit(static_cast<unsigned char>(str[i])))
        {
            has_digit = true;
        }
        else
            return false;
    }

    return has_digit && (dot == 1);
}

bool is_it_special(const std::string& str)
{
    return (str == "nan"  || str == "nanf"  ||
            str == "+inf" || str == "+inff" ||
            str == "-inf" || str == "-inff" ||
            str == "inf"  || str == "inff");
}

InputType pars_input(const std::string &input)
{

    if (is_it_char(input))
        return Type_CHAR;
    else if (is_it_int(input))
        return Type_INT;
    else if (is_it_double(input))
        return Type_DOUBLE;
    else if (is_it_float(input))
        return Type_FLOAT;
    else if (is_it_special(input))
        return Type_SPECIAL;
    else
        return Type_INVALID;
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
    errno = 0;
    long value = std::strtol(input.c_str(), NULL, 10);
    std::cout << "char: ";
    if (errno == ERANGE || value < CHAR_MIN || value > CHAR_MAX)
        std::cout << "impossible";
    else if (!std::isprint(static_cast<unsigned char>(value)))
        std::cout << "Non displayable";
    else
        std::cout << "'" << static_cast<char>(value) << "'";
    std::cout << std::endl;

    std::cout << "int: ";
    if (errno == ERANGE || value < INT_MIN || value > INT_MAX)
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