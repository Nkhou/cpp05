/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:21:02 by nkhoudro          #+#    #+#             */
/*   Updated: 2024/02/14 16:18:27 by nkhoudro         ###   ########.fr       */
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

AForm *Intern::makeForm(std::string name, std::string target)
{
    AForm *AForm = NULL;
    AForm = AForm->makeForm(name, target);
    if (AForm == NULL)
    {
        throw Intern::AFormNotFoundException();
    }
    return AForm;
}
const char *Intern::AFormNotFoundException::what() const throw()
{
    return "AForm not found";
}
Intern::~Intern()
{
}