/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:21:21 by nkhoudro          #+#    #+#             */
/*   Updated: 2024/02/14 19:56:50 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm_H
#define PresidentialPardonForm_H
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
    private:
        std::string target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const &other);
        ~PresidentialPardonForm();
        PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
        void execute(Bureaucrat const &executor) const;
        Form *makeForm(Form *Form, std::string name, std::string target);
};
#endif