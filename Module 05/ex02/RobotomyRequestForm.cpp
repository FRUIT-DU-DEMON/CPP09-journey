/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:24:12 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/17 22:17:46 by hlabouit         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include"RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm(), target("target")//subobject must be intialized first
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &which_target) : AForm("rbtForm", 72, 45), target(which_target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &primary) : AForm(primary), target(primary.target)
{
	*this = primary;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &primary)
{
	if (this != &primary)
		AForm::operator=(primary);
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	check_requirements(executor);
	std::cout<< "TRRRRRRRRRRRRR..." ;
	static int random;
	if (random % 2 == 0)
		std::cout<< this->target << " has been robotomized successfully '50%' of the time" << std::endl;
	else
		std::cout<< "robotomy failed to robotomize " << this->target << std::endl;
	random++;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}