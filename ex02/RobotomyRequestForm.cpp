/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:20:00 by nkhoudro          #+#    #+#             */
/*   Updated: 2024/02/14 20:24:46 by nkhoudro         ###   ########.fr       */
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
    static int count = 0;
    if (!getSigne())
        throw AForm::AFormNotSignedException();
    if (executor.getGrade() > getGradeExec())
        throw AForm::GradeTooLowException();
    if (count % 2 == 0)
        std::cout << this->target << " has been robotomized successfully" << std::endl;
    else
        std::cout << this->target << " faild to robotomized" << std::endl;
    count++;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
}
