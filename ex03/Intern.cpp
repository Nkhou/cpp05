/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:21:02 by nkhoudro          #+#    #+#             */
/*   Updated: 2024/02/14 20:08:51 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
    Form *Form = NULL;
    Form = Form->makeForm(name, target);
    if (Form == NULL)
    {
        throw Intern::FormNotFoundException();
    }
    return Form;
}
const char *Intern::FormNotFoundException::what() const throw()
{
    return "Form not found";
}
Intern::~Intern()
{
}