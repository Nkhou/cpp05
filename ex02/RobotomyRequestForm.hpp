/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:20:05 by nkhoudro          #+#    #+#             */
/*   Updated: 2024/02/14 20:23:26 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RobotomyRequestFORM_H
#define RobotomyRequestFORM_H
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
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
};
#endif