/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:19:14 by nkhoudro          #+#    #+#             */
/*   Updated: 2024/02/14 16:13:37 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AForm_H
#define AForm_H

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;
class AForm
{
    private:
        std::string Name;
        bool signe;
        int gradeSign;
        int gradeExec;
    public:
        AForm();
        AForm(std::string name, int gradeSign, int gradeExec);
        AForm(AForm const &other);
        AForm &operator=(AForm const &other);
        virtual ~AForm();
        std::string getName() const;
        bool getSigne() const;
        int getGradeSign() const;
        int getGradeExec() const;
        void beSigned(Bureaucrat &bureaucrat);
        class AFormNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
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
        virtual void  execute(Bureaucrat const &executor) const = 0;
};

std::ostream& operator<<(std::ostream& out, AForm &AForm);

#endif