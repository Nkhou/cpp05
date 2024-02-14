/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:18:45 by nkhoudro          #+#    #+#             */
/*   Updated: 2024/02/14 17:57:31 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef Form_H
#define Form_H

#include "Bureaucrat.hpp"
class Bureaucrat;
class Form
{
    private:
        std::string const Name;
        bool signe;
        int const gradeSign;
        int const gradeExec;
    public:
        Form();
        Form(std::string name, int gradeSign, int gradeExec);
        Form(Form const &other);
        Form &operator=(Form const &other);
        ~Form();
        std::string getName() const;
        bool getSigne() const;
        int getGradeSign() const;
        int getGradeExec() const;
        void beSigned(Bureaucrat &bureaucrat);
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
        
};
std::ostream& operator<<(std::ostream& out, Form &Form);


#endif