#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H
#include "AForm.hpp"
class RobotomyRequestForm : public Form
{
    private:
        std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const &other);
        ~RobotomyRequestForm();
        RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
        void execute(Bureaucrat const &executor) const;
        Form *makeForm(Form *form, std::string name, std::string target);
};
#endif