#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name_form;
        bool                _is_signed;
        const int           _grade_to_sign;
        const int           _grade_to_execute;
    public:

        AForm();
        AForm(const std::string& name, int GradeToSign, int GradeToExecute);
        AForm(const AForm& src);
        AForm& operator=(const AForm& src);
        virtual ~AForm(); // need to prove its usage 

        std::string getNameForm() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        static int checkGradeForm(int grade);
        class GradeTooHighException : public std::exception
        {
            public :
                virtual const char* what() const throw();
                
        };
        class GradeTooLowException : public std::exception
        {
            public :
                virtual const char* what() const throw();
                
        };
        class FormNotSignedException : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };
        
        void beSigned(const Bureaucrat& bureaucrat);
        virtual void execute(Bureaucrat const &executor) const = 0;
        // void executAction(Bureaucrat const & executor);


};
std::ostream& operator<<(std::ostream& out, const AForm& form_obj);

#endif