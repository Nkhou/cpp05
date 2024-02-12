#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(std::string name) : name(name)
{
}

Intern::Intern(Intern const &other)
{
    *this = other;
}

Intern &Intern::operator=(Intern const &other)
{
    if (this != &other)
    {
        this->name = other.name;
    }
    return *this;
}

Form *Intern::makeForm(std::string name, std::string target)
{
    if (name == "ShrubberyCreationForm")
    {
        return new ShrubberyCreationForm(target);
    }
    else if (name == "RobotomyRequestForm")
    {
        return new RobotomyRequestForm(target);
    }
    else if (name == "PresidentialPardonForm")
    {
        return new PresidentialPardonForm(target);
    }
    else
    {
        throw Intern::FormNotFoundException();
    }
}
const char *Intern::FormNotFoundException::what() const throw()
{
    return "Form not found";
}
Intern::~Intern()
{
}