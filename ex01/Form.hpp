/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:26:43 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/11 00:01:04 by hlabouit         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FORM_H
# define FORM_H

#include"Bureaucrat.hpp"

class Form {
    private:
        const std::string name;
        bool if_signed;
        const int grade_sg;
        const int grade_ex;
    public:
        Form();
        Form(const std::string &which_name, int which_grade_sg, int which_grade_ex);
        Form(const Form &primary);
        Form &operator=(const Form &primary);
        const std::string &getName() const;
		int getGrade_sg() const;
		int getGrade_ex() const;
        void beSigned(const Bureaucrat &brc);
        ////// exeption classes //////
        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw() {return ("GRADE IS OUT OF RANGE!");}

        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw() {return ("GRADE IS OUT OF RANGE!");}
        };
        ////// exeption classes //////
        ~Form();
        
};

std::ostream &operator<<(std::ostream &output_console, const Form &brc_form);


#endif