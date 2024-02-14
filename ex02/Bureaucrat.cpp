/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:19:19 by nkhoudro          #+#    #+#             */
/*   Updated: 2024/02/14 16:13:37 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

std::ostream& operator<<(std::ostream& out, Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}

void Bureaucrat::signAForm(AForm &AForm)
{
    try
    {
        AForm.beSigned(*this);
        std::cout << _name << " signs " << AForm.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << _name << " cannot sign " << AForm.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeAForm(AForm const &AForm)
{
    if (AForm.getSigne() == false)
        std::cout << _name << " cannot execute " << AForm.getName() << " because " << "AForm is not signed" << std::endl;
    else if (_grade > AForm.getGradeExec())
        std::cout << _name << " cannot execute " << AForm.getName() << " because " << "Grade is too low" << std::endl;
    else
    {
        AForm.execute(*this);
        std::cout << _name << " executes " << AForm.getName() << std::endl;
    }
}