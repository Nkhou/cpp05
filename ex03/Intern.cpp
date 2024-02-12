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
    Form *form = NULL;
    form = form->makeForm(name, target);
    if (form == NULL)
    {
        throw Intern::FormNotFoundException();
    }
    return form;
}
const char *Intern::FormNotFoundException::what() const throw()
{
    return "Form not found";
}
Intern::~Intern()
{
}