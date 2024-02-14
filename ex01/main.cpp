/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:18:51 by nkhoudro          #+#    #+#             */
/*   Updated: 2024/02/14 20:01:55 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat Bureaucrat("najat", 1);
        Form Form("Form", 2, 30);
        Bureaucrat.signForm(Form);
        // Bureaucrat.increment();
        // Bureaucrat.decrement();
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}