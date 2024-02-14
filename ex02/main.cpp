/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:19:34 by nkhoudro          #+#    #+#             */
/*   Updated: 2024/02/14 20:28:13 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat Bureaucrat("najat", 10);
        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("home");
        PresidentialPardonForm presidential("home");
        Bureaucrat.signForm(shrubbery);
        Bureaucrat.executeForm(shrubbery);
        Bureaucrat.signForm(robotomy);
        Bureaucrat.executeForm(robotomy);
        Bureaucrat.signForm(presidential);
        Bureaucrat.executeForm(presidential);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}