#include "ScalarConverter.hpp"

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