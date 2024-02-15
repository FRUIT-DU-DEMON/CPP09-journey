/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 00:12:36 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/15 02:12:32 by hlabouit         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

#include"AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &which_target);
		ShrubberyCreationForm(const ShrubberyCreationForm &primary);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &primary);
		void execute(Bureaucrat const &executor) const;
		class NotOpened : public std::exception {
        	public:
                virtual const char *what() const throw() {return ("FAILED TO OPEN THE TARGET FILE!");}
        };
		~ShrubberyCreationForm();
};

#endif