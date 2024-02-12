#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), target(target)
{
}
RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45), target("default")
{
}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : Form("RobotomyRequestForm", 72, 45)
{
    *this = other;
}
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
    if (this != &other)
    {
        this->target = other.target;
    }
    return *this;
}
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!getSigne())
        throw Form::FormNotSignedException();
    if (executor.getGrade() > getGradeExec())
        throw Form::GradeTooLowException();
     std::cout << this->target << " has been robotomized successfully 50% of the time" << std::endl;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
}
