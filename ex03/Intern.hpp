/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:21:07 by nkhoudro          #+#    #+#             */
/*   Updated: 2024/02/14 16:18:27 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INTERN_H
#define INTERN_H
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
class Intern
{
    private:
        std::string name;
    public:
        Intern();
        Intern(std::string name);
        Intern(Intern const &other);
        ~Intern();
        Intern &operator=(Intern const &other);
        AForm *makeForm(std::string name, std::string target);
        class AFormNotFoundException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};
#endif