/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:20:58 by nkhoudro          #+#    #+#             */
/*   Updated: 2024/02/14 19:56:15 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUROCRAT_HPP
#define BUROCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;
class Bureaucrat
{
    private:
        std::string const _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(Bureaucrat const &other);
        Bureaucrat &operator=(Bureaucrat const &other);
        ~Bureaucrat();
        std::string getName() const;
        int getGrade() const;
        void increment();
        void decrement();
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        void signForm(Form &Form);
        void executeForm(Form const &Form);
};
std::ostream& operator<<(std::ostream out, Bureaucrat &bureaucrat);
#endif