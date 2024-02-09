#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat Bureaucrat("najat", 150);
        Form form("form", 150, 30);
        Bureaucrat.signForm(form);
        // Bureaucrat.increment();
        // Bureaucrat.decrement();
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}