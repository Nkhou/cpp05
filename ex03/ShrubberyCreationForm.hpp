/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:21:39 by nkhoudro          #+#    #+#             */
/*   Updated: 2024/02/14 19:58:46 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ShrubberyCreationForm_H
#define ShrubberyCreationForm_H
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const &other);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
        void execute(Bureaucrat const &executor) const;
        Form *makeForm(Form *Form, std::string name, std::string target);
        class FileNotOpenedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        
};
#endif