#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}
Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name)
{
    *this = other; 
}
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
    _grade = other._grade;
    return *this;
}
Bureaucrat::~Bureaucrat()
{
}
std::string Bureaucrat::getName() const
{
    return _name;
}
int Bureaucrat::getGrade() const
{
    return _grade;
}
void Bureaucrat::increment()
{
    if (_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}
void Bureaucrat::decrement()
{
    if (_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}
const char*Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}
const char*Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}
// Bureaucrat::GradeTooLowException::GradeTooLowException()
// {
// }

// Bureaucrat::GradeTooHighException::GradeTooHighException()
// {
// }
// Bureaucrat::GradeTooHighException::~GradeTooHighException()
// {
// }
// Bureaucrat::GradeTooLowException::~GradeTooLowException()
// {
// }

std::ostream& operator<<(std::ostream& out, Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signs " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << _name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
    }
}