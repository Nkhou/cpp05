/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:20:00 by nkhoudro          #+#    #+#             */
/*   Updated: 2024/02/14 16:16:35 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default")
{
}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm("RobotomyRequestForm", 72, 45)
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
    if (!getSigne())
        throw AForm::AFormNotSignedException();
    if (executor.getGrade() > getGradeExec())
        throw AForm::GradeTooLowException();
     std::cout << this->target << " has been robotomized successfully 50% of the time" << std::endl;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
}
