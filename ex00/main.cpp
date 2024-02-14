/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:18:08 by nkhoudro          #+#    #+#             */
/*   Updated: 2024/02/14 18:21:59 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat Bureaucrat;
        Bureaucrat.increment();
        std::cout << Bureaucrat << std::endl;
        Bureaucrat.decrement();
        std::cout << Bureaucrat << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

}