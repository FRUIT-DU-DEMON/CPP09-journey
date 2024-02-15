/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 01:23:28 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/15 14:45:18 by hlabouit         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include"ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), target("target")//subobject must be intialized first
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &which_target) : AForm("shbForm", 145, 137), target(which_target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &primary) : AForm(primary)
{
    *this = primary;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &primary)
{
    if (this != &primary)
        AForm::operator=(primary);
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    check_requirements(executor);
	std::string tmp = this->target + "_shrubbery";
    std::ofstream tree(tmp.c_str());
    if (!tree.is_open())
        throw ShrubberyCreationForm::NotOpened();
	else
	{
		tree << "      *      " << std::endl;
        tree << "     ***     " << std::endl;
        tree << "    *****    " << std::endl;
        tree << "   *******   " << std::endl;
        tree << "  *********  " << std::endl;
        tree << " *********** " << std::endl;
        tree << "     |||     " << std::endl;
        tree << "     |||     " << std::endl;
        tree << "     |||     " << std::endl;
	}
	tree.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}