/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 23:54:47 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/16 17:27:03 by hlabouit         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include"PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(), target("target")//subobject must be intialized first
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &which_target) : AForm("prpForm", 25, 5), target(which_target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &primary) : AForm(primary), target(primary.target)
{
	*this = primary;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &primary)
{
	if (this != &primary)
		AForm::operator=(primary);
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	check_requirements(executor);
    std::cout<< this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}