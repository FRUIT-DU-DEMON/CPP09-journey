/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:20:03 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/15 15:21:50 by hlabouit         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

#include"AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		const std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &which_target);
		RobotomyRequestForm(const RobotomyRequestForm &primary);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &primary);
		void execute(Bureaucrat const &executor) const;
		~RobotomyRequestForm();
};

#endif