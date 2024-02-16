/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:37:34 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/16 01:48:05 by hlabouit         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include"Bureaucrat.hpp"
#include"ShrubberyCreationForm.hpp"
#include"RobotomyRequestForm.hpp"
#include"PresidentialPardonForm.hpp"

int main()
{
	try
    {
        Bureaucrat brc("vanGogh", 1);
        Bureaucrat brc2("chiHed", 1);
        ShrubberyCreationForm sh("tst");
        RobotomyRequestForm rb("tst2");
        PresidentialPardonForm pr("tst3");
        brc2.signForm(sh);
        brc2.executeForm(sh);
        brc.signForm(sh);
        brc.signForm(rb);
        brc.signForm(pr);
        sh.execute(brc);
        rb.execute(brc);
        pr.execute(brc);
    }
    catch(const std::exception &excp)
    {
        std::cout << excp.what() << std::endl;
    }
    return (0);
}