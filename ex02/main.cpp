/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:19:34 by nkhoudro          #+#    #+#             */
/*   Updated: 2024/02/14 18:00:38 by nkhoudro         ###   ########.fr       */
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
        Bureaucrat.signAForm(shrubbery);
        Bureaucrat.executeAForm(shrubbery);
        Bureaucrat.signAForm(robotomy);
        Bureaucrat.executeAForm(robotomy);
        Bureaucrat.signAForm(presidential);
        Bureaucrat.executeAForm(presidential);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}