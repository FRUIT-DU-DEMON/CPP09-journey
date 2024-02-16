/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:06:06 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/16 21:28:13 by hlabouit         ###   ########.fr       */
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
        ~Intern();
};

#endif