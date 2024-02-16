/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:46:46 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/16 01:06:18 by hlabouit         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>
#include<ctype.h>
#include<cstdlib>
#include<cmath>

#include"AForm.hpp"
class AForm;

class Bureaucrat {
	private:
		const std::string name;
		int grade;//!!usgnd
	public:
		Bureaucrat();
        Bureaucrat(const std::string &which_name, int which_grade);
		Bureaucrat(const Bureaucrat &primary);
		Bureaucrat &operator=(const Bureaucrat &primary);
		const std::string &getName() const;
		int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm &form);//takes a reference to AForm through a class inherits from AForm since it has a subObject part and an abstract class cant be instantiated on it's own because it's incomplete
        void executeForm(AForm const & form);
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
		~Bureaucrat();
};

std::ostream &operator<<(std::ostream &output_console, const Bureaucrat &brc);

#endif
