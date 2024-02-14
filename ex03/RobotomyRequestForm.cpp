/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:21:25 by nkhoudro          #+#    #+#             */
/*   Updated: 2024/02/14 20:28:50 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), target(target)
{
}
RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45), target("default")
{
}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : Form("RobotomyRequestForm", 72, 45)
{
    *this = other;
}
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
    if (this != &other)
    {
        this->target = other.target;
    }
    return *this;
}
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    static int count = 0;
    if (!getSigne())
        throw Form::FormNotSignedException();
    if (executor.getGrade() > getGradeExec())
        throw Form::GradeTooLowException();
    if (count % 2 == 0)
        std::cout << this->target << " has been robotomized successfully" << std::endl;
    else
        std::cout << this->target << " faild to robotomized" << std::endl;
    count++;
}
Form *RobotomyRequestForm::makeForm(Form *Form, std::string name, std::string target)
{
    if (name == "RobotomyRequestForm")
        Form = new RobotomyRequestForm(target);
    return Form;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
}
