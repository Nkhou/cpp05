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
    file << "     /\\\\     " << std::endl;
    file << "    /\\\\\\    " << std::endl;
    file << "   /*/\\\\\\   " << std::endl;
    file << "  /\\O\\\\/\\  " << std::endl;
    file << " /\\*\\/\\*/\\ " << std::endl;
    file << "/\\O\\/\\/*//\\" << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file <<  "     ||      " << std::endl;
    file.close();
}

const char*ShrubberyCreationForm::FileNotOpenedException::what() const throw()
{
    return "File is not opened";
}
