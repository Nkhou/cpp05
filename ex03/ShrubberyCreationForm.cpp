/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:21:34 by nkhoudro          #+#    #+#             */
/*   Updated: 2024/02/14 19:58:28 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), target("default")
{
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), target(target)
{
}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : Form("ShrubberyCreationForm", 145, 137)
{
    *this = other;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
    if (this != &other)
    {
        this->target = other.target;
    }
    return *this;
}
Form *ShrubberyCreationForm::makeForm(Form *Form, std::string name, std::string target)
{
    if (name == "ShrubberyCreationForm")
        Form = new ShrubberyCreationForm(target);
    return Form;
}
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!getSigne())
        throw Form::FormNotSignedException();
    if (executor.getGrade() > getGradeExec())
        throw Form::GradeTooLowException();
    std::ofstream file(std::string(this->target + "_shrubbery").c_str());
    if (!file.is_open())
        throw ShrubberyCreationForm::FileNotOpenedException();
     file << "      /\\      " << std::endl;
    file << "     /\\\\\\     " << std::endl;
    file << "    /\\\\*\\\\    " << std::endl;
    file << "   /*/\\\\\\*\\   " << std::endl;
    file << "  /\\O\\*\\O\\/\\  " << std::endl;
    file << " /\\*\\*/\\*\\*/\\ " << std::endl;
    file << "/\\O\\/\\O\\/*///\\" << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file <<  "      ||      " << std::endl;
    file.close();
}

const char*ShrubberyCreationForm::FileNotOpenedException::what() const throw()
{
    return "File is not opened";
}
