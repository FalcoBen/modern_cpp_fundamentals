#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>

enum InputType {
    Type_CHAR,
    Type_INT,
    Type_FLOAT,
    Type_DOUBLE,
    Type_SPECIAL,
    Type_INVALID 
};


class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& src);
        ScalarConverter& operator=(const ScalarConverter& src);
        ~ScalarConverter();
        
    public:
        static void convert(const std::string& input);
};

InputType pars_input(const std::string &input);

#endif
