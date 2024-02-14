/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:21:11 by nkhoudro          #+#    #+#             */
/*   Updated: 2024/02/14 16:18:27 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        Bureaucrat Bureaucrat("najat", 10);
        Intern intern;
        AForm *AForm;
        AForm = intern.makeForm("ShrubberyCreationForm", "home");
        Bureaucrat.signAForm(*AForm);
        Bureaucrat.executeAForm(*AForm);
        AForm = intern.makeForm("RobotomyRequestForm", "home");
        Bureaucrat.signAForm(*AForm);
        Bureaucrat.executeAForm(*AForm);
        AForm = intern.makeForm("PresidentialPardonForm", "home");
        Bureaucrat.signAForm(*AForm);
        Bureaucrat.executeAForm(*AForm);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}