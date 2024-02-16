/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:54:24 by nkhoudro          #+#    #+#             */
/*   Updated: 2024/02/16 14:42:27 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

AForm::AForm() : Name("default"), signe(false), gradeSign(1), gradeExec(1)
{
}
AForm::AForm(std::string name, int gradeSign, int gradeExec) : Name(name), signe(false), gradeSign(gradeSign), gradeExec(gradeExec)
{
    if (gradeSign < 1 || gradeExec < 1)
        throw AForm::GradeTooHighException();
    else if (gradeSign > 150 || gradeExec > 150)
        throw AForm::GradeTooLowException();
}
AForm::AForm(AForm const &other) : Name(other.Name)
{
    *this = other;
}
AForm &AForm::operator=(AForm const &other)
{
    signe = other.signe;
    return *this;
}
AForm::~AForm()
{
}
std::string AForm::getName() const
{
    return Name;
}
bool AForm::getSigne() const
{
    return signe;
}
int AForm::getGradeSign() const
{
    return gradeSign;
}
int AForm::getGradeExec() const
{
    return gradeExec;
}
void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > gradeSign)
        throw AForm::GradeTooLowException();
    signe = true;
}
const char*AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}
const char*AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}
const char*AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

std::ostream& operator<<(std::ostream& out, AForm &AForm)
{
    out << "Form " << AForm.getName() << " is ";
    if (AForm.getSigne())
        out << "signed";
    else
        out << "not signed";
    out << " and requires grade " << AForm.getGradeSign() << " to be signed and grade " << AForm.getGradeExec() << " to be executed";
    return out;
}

AForm *AForm::makeForm(std::string name, std::string target)
{
    AForm *Form = NULL;
    PresidentialPardonForm PresidentialPardonForm(target);
    Form = PresidentialPardonForm.makeForm(Form, name, target);
    ShrubberyCreationForm ShrubberyCreationForm(target);
    Form = ShrubberyCreationForm.makeForm(Form, name, target);
    RobotomyRequestForm RobotomyRequestForm(target);
    Form = RobotomyRequestForm.makeForm(Form, name, target);
    if (Form != NULL)
    {
        std::cout << "Intern creates " << Form->getName() << std::endl;
        return Form;
    }
    return NULL;
}