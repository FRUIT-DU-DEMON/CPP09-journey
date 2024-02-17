/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:26:43 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/15 04:32:42 by hlabouit         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef AFORM_H
# define AFORM_H

#include"Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string name;
        bool if_signed;
        const int grade_sg;
        const int grade_ex;
    public:
        AForm();
        AForm(const std::string &which_name, int which_grade_sg, int which_grade_ex);
        AForm(const AForm &primary);
        AForm &operator=(const AForm &primary);
        const std::string &getName() const;
        bool getSign() const;
		int getGrade_sg() const;
		int getGrade_ex() const;
        void beSigned(Bureaucrat brc);
        void check_requirements(Bureaucrat brc) const;
        void virtual execute(Bureaucrat const &executor) const = 0;//pure virtual function
        ////// exeption classes //////
        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw() {return ("GRADE IS OUT OF RANGE!");}

        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw() {return ("GRADE IS OUT OF RANGE!");}
        };
        class UnsignedForm : public std::exception {
            public:
                virtual const char *what() const throw() {return ("FORM ISN't SIGNED!");}
        };
        ////// exeption classes //////
        ~AForm();
};

std::ostream &operator<<(std::ostream &output_console, const AForm &brc_form);

#endif