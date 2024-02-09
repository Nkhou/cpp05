#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"
class Bureaucrat;
class Form
{
    private:
        std::string Name;
        bool signe;
        int gradeSign;
        int gradeExec;
    public:
        Form(std::string name, int gradeSign, int gradeExec);
        Form(Form const &other);
        Form &operator=(Form const &other);
        ~Form();
        std::string getName() const;
        bool getSigne() const;
        int getGradeSign() const;
        int getGradeExec() const;
        void beSigned(Bureaucrat &bureaucrat);
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
};

std::ostream& operator<<(std::ostream out, Form &form);


#endif