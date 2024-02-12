#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat Bureaucrat("najat", 10);
        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("home");
        PresidentialPardonForm presidential("home");

        Bureaucrat.signForm(shrubbery);
        Bureaucrat.executeForm(shrubbery);
        Bureaucrat.signForm(robotomy);
        Bureaucrat.executeForm(robotomy);
        Bureaucrat.signForm(presidential);
        Bureaucrat.executeForm(presidential);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}