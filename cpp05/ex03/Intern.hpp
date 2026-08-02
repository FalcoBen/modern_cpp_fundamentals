#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
class AForm;
class Intern
{
    private:
        AForm* _create_robotomy(const std::string& target);
        AForm* _create_shrubbery(const std::string& target);
        AForm* _create_presidential(const std::string& target);
    public:
        Intern();
        Intern(const Intern& src);
        Intern& operator=(const Intern& src);
        ~Intern();
        AForm* makeForm(const std::string& name_of_form, const std::string& target_form);
};

#endif