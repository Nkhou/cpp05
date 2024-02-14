/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:21:29 by nkhoudro          #+#    #+#             */
/*   Updated: 2024/02/14 19:57:59 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RobotomyRequestForm_H
#define RobotomyRequestForm_H
#include "Form.hpp"
class RobotomyRequestForm : public Form
{
    private:
        std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const &other);
        ~RobotomyRequestForm();
        RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
        void execute(Bureaucrat const &executor) const;
        Form *makeForm(Form *Form, std::string name, std::string target);
};
#endif