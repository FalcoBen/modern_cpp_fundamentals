#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
class Bureaucrat;

class Form
{
    private:
        const std::string   _name_form;
        bool                _is_signed;
        const int           _grade_to_sign;
        const int           _grade_to_execute;
        static int _checkGradeForm(int grade);
    public:
        
        Form();
        Form(const std::string& name, int GradeToSign, int GradeToExecute);
        Form(const Form& src);
        Form& operator=(const Form& src);
        ~Form();

        std::string getNameForm() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        class GradeTooHighException : public std::exception
        {
            public :
                virtual const char* what() const throw();
                ~GradeTooHighException() throw();
        };
        class GradeTooLowException : public std::exception
        {
            public :
                virtual const char* what() const throw();
                ~GradeTooLowException() throw();
        };
        
        void beSigned(const Bureaucrat& bureaucrat);

};

std::ostream& operator<<(std::ostream& out, const Form& form_obj);

#endif