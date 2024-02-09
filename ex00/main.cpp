#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat Bureaucrat("najat", 151);
        // Bureaucrat.increment();
        Bureaucrat.decrement();
    }
    catch(Bureaucrat::GradeTooHighException& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException& e)
    {
        std::cout << e.what() << std::endl;
    }
}