/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 23:50:45 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/15 23:51:59 by hlabouit         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

#include"AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		const std::string target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &which_target);
		PresidentialPardonForm(const PresidentialPardonForm &primary);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &primary);
		void execute(Bureaucrat const &executor) const;
		~PresidentialPardonForm();
};

#endif