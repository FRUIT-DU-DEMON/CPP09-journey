/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:46:46 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/09 22:14:33 by hlabouit         ###   ########.fr       */
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
        ////// exeption classes //////
        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw() {return ("GRADE IS OUT OF RANGE!");}
                //costum exeption classes inherit from std::exception baseclass
                //what() provides a description of the exception and returns a C style char*
                //where thow() is an exception specifications that specifies that what() doesn't throw exceptions

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
