/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:20:45 by nkhoudro          #+#    #+#             */
/*   Updated: 2024/02/14 16:18:27 by nkhoudro         ###   ########.fr       */
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
const char*AForm::AFormNotSignedException::what() const throw()
{
    return "AForm is not signed";
}

std::ostream& operator<<(std::ostream& out, AForm &AForm)
{
    out << "AForm " << AForm.getName() << " is ";
    if (AForm.getSigne())
        out << "signed";
    else
        out << "not signed";
    out << " and requires grade " << AForm.getGradeSign() << " to be signed and grade " << AForm.getGradeExec() << " to be executed";
    return out;
}

AForm *AForm::makeForm(std::string name, std::string target)
{
    AForm *AForm = NULL;
    PresidentialPardonForm PresidentialPardonForm(target);
    AForm = PresidentialPardonForm.makeForm(AForm, name, target);
    ShrubberyCreationForm ShrubberyCreationForm(target);
    AForm = ShrubberyCreationForm.makeForm(AForm, name, target);
    RobotomyRequestForm RobotomyRequestForm(target);
    AForm = RobotomyRequestForm.makeForm(AForm, name, target);
    if (AForm != NULL)
    {
        std::cout << "Intern creates " << AForm->getName() << std::endl;
        return AForm;
    }
    return NULL;
}