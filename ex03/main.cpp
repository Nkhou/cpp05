/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:21:11 by nkhoudro          #+#    #+#             */
/*   Updated: 2024/02/14 20:30:11 by nkhoudro         ###   ########.fr       */
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
        Form *Form;
        Form = intern.makeForm("ShrubberyCreationForm", "home");
        Bureaucrat.signForm(*Form);
        Bureaucrat.executeForm(*Form);
        Form = intern.makeForm("RobotomyRequestForm", "home");
        Bureaucrat.signForm(*Form);
        Bureaucrat.executeForm(*Form);
        Form = intern.makeForm("PresidentialPardonForm", "home");
        Bureaucrat.signForm(*Form);
        Bureaucrat.executeForm(*Form);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}