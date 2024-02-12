#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H
#include "AForm.hpp"

class PresidentialPardonForm : public Form
{
    private:
        std::string target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const &other);
        ~PresidentialPardonForm();
        PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
        void execute(Bureaucrat const &executor) const;
};
#endif