#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        Bureaucrat Bureaucrat("najat", 10);
        Intern intern;
        Form *form;
        form = intern.makeForm("ShrubberyCreationForm", "home");
        Bureaucrat.signForm(*form);
        Bureaucrat.executeForm(*form);
        form = intern.makeForm("RobotomyRequestForm", "home");
        Bureaucrat.signForm(*form);
        Bureaucrat.executeForm(*form);
        form = intern.makeForm("PresidentialPardonForm", "home");
        Bureaucrat.signForm(*form);
        Bureaucrat.executeForm(*form);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}