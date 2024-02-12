#ifndef INTERN_H
#define INTERN_H
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
class Intern
{
    private:
        std::string name;
    public:
        Intern();
        Intern(std::string name);
        Intern(Intern const &other);
        ~Intern();
        Intern &operator=(Intern const &other);
        Form *makeForm(std::string name, std::string target);
        class FormNotFoundException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};
#endif