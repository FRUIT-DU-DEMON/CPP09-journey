/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:06:06 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/17 22:05:53 by hlabouit         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef INTERN_H
# define INTERN_H

#include"AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &primary);
		Intern &operator=(const Intern &primary);
        AForm *makeForm(const std::string &which_form_name, const std::string &which_form_target);
        class UnmatchedName : public std::exception {
            public:
                virtual const char *what() const throw() {return ("no matching name of the form to be crated!");}
        };
        ~Intern();
};

#endif