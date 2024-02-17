/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:37:34 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/17 22:23:41 by hlabouit         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include"Bureaucrat.hpp"
#include"ShrubberyCreationForm.hpp"
#include"RobotomyRequestForm.hpp"
#include"PresidentialPardonForm.hpp"
#include"Intern.hpp"

int main()
{
	try
    {
        Bureaucrat brc("vanGogh", 1);
        Intern intern;
        AForm *form;

        form = intern.makeForm("presidential pardon", "Bender");
        brc.signForm(*form);
        form->execute(brc);
        delete form;
        form = intern.makeForm("DOESN'T EXIST", "target");
    }
    catch(const std::exception &excp)
    {
        std::cout << excp.what() << std::endl;
    }
    return (0);
}