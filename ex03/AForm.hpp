#ifndef Form_H
#define Form_H

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;
class Form
{
    private:
        std::string Name;
        bool signe;
        int gradeSign;
        int gradeExec;
    public:
        Form();
        Form(std::string name, int gradeSign, int gradeExec);
        Form(Form const &other);
        Form &operator=(Form const &other);
        virtual ~Form();
        std::string getName() const;
        bool getSigne() const;
        int getGradeSign() const;
        int getGradeExec() const;
        void beSigned(Bureaucrat &bureaucrat);
        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
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
        virtual void  execute(Bureaucrat const &executor) const = 0;
        Form *makeForm(std::string name, std::string target);
};

std::ostream& operator<<(std::ostream out, Form &Form);


#endif