#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class AForm;

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;
        static int _CheckGrade(int grade);
        
    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& src);
        Bureaucrat& operator=(const Bureaucrat& src);
        ~Bureaucrat();
        std::string getName() const;
        int         getGrade() const;
        void        increment_grade();
        void        decrement_grade();
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
        void signForm(AForm& form_obj);
        void executeForm(AForm const & form) const;
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat& bureaucrat);

#endif
