/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:19:52 by nkhoudro          #+#    #+#             */
/*   Updated: 2024/02/14 16:17:41 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PresidentialPardonForm_H
#define PresidentialPardonForm_H
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
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
};
#endif