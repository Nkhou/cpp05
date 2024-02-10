#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat Bureaucrat("najat", 150);
        Form Form("Form", 1, 30);
        Bureaucrat.signForm(Form);
        // Bureaucrat.increment();
        // Bureaucrat.decrement();
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}