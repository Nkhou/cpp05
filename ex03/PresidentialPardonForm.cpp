/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:21:16 by nkhoudro          #+#    #+#             */
/*   Updated: 2024/02/14 19:57:36 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), target(target)
{
}
PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5), target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : Form("PresidentialPardonForm", 25, 5)
{
    *this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
    if (this != &other)
    {
        this->target = other.target;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!getSigne())
        throw Form::FormNotSignedException();
    if (executor.getGrade() > getGradeExec())
        throw Form::GradeTooLowException();
    std::cout << this->target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
Form *PresidentialPardonForm::makeForm(Form *Form, std::string name, std::string target)
{
    if (name == "PresidentialPardonForm")
        Form = new PresidentialPardonForm(target);
    return Form;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
}
