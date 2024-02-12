#ifndef BUROCRAT_HPP
#define BUROCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class Form;
class Bureaucrat
{
    private:
        std::string const _name;
        int _grade;
    public:
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(Bureaucrat const &other);
        Bureaucrat &operator=(Bureaucrat const &other);
        ~Bureaucrat();
        std::string getName() const;
        int getGrade() const;
        void increment();
        void decrement();
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        void signForm(Form &Form);
        void executeForm(Form const &form);
};
std::ostream& operator<<(std::ostream out, Bureaucrat &bureaucrat);
#endif