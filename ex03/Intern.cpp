/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:31:12 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/17 21:59:56 by hlabouit         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include"Intern.hpp"
#include"ShrubberyCreationForm.hpp"
#include"RobotomyRequestForm.hpp"
#include"PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &primary)
{
    *this = primary;
}

Intern &Intern::operator=(const Intern &primary)
{
    (void)primary;
	return (*this);
}

AForm *Intern::makeForm(const std::string &which_form_name, const std::string &which_form_target)
{
    std::string form_name[3] = {"shForm", "rbForm", "prForm"};
    AForm *formPtr [3] = {new ShrubberyCreationForm(which_form_target),
						new RobotomyRequestForm(which_form_target),
						new PresidentialPardonForm(which_form_target)};
    for (int i = 0; i < 3; i++)
    {
        if (which_form_name == form_name[i])
        {
            std::cout<< "Intern creates " << form_name[i] << std::endl;
            if (i == 1)
                return (delete formPtr[abs(i - 1)], delete formPtr[abs(i + 1)], formPtr[i]);
            else
                return (delete formPtr[abs(i - 1)], delete formPtr[abs(i - 2)], formPtr[i]);
        }
    }
    std::cout<< "no matching form name for " << which_form_name << "!" << std::endl;
	for (int i = 0; i < 3; i++)
		delete formPtr[i];
    return (NULL);
}

Intern::~Intern()
{
}

// i = 0:  d1 d2
// i = 1:  d0 d2
// i = 2:  d1 d0