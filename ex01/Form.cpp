/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:18:36 by nkhoudro          #+#    #+#             */
/*   Updated: 2024/02/14 17:57:22 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"

Form::Form(std::string name, int gradeSign, int gradeExec) : Name(name), signe(false), gradeSign(gradeSign), gradeExec(gradeExec)
{
    if (gradeSign < 1 || gradeExec < 1)
        throw Form::GradeTooHighException();
    else if (gradeSign > 150 || gradeExec > 150)
        throw Form::GradeTooLowException();
}
Form::Form(Form const &other) : Name(other.Name)
{
    *this = other;
}
Form &Form::operator=(Form const &other)
{
    signe = other.signe;
    return *this;
}
Form::~Form()
{
}
std::string Form::getName() const
{
    return Name;
}
bool Form::getSigne() const
{
    return signe;
}
int Form::getGradeSign() const
{
    return gradeSign;
}
int Form::getGradeExec() const
{
    return gradeExec;
}
void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > gradeSign)
        throw Form::GradeTooLowException();
    signe = true;
}
const char*Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}
const char*Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}
std::ostream& operator<<(std::ostream& out, Form &Form)
{
    out << "Form " << Form.getName() << " is ";
    if (Form.getSigne())
        out << "signed";
    else
        out << "not signed";
    out << " and requires grade " << Form.getGradeSign() << " to be signed and grade " << Form.getGradeExec() << " to be executed";
    return out;
}