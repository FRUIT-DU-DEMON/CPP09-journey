/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:37:34 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/16 17:57:53 by hlabouit         ###   ########.fr       */
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
        ShrubberyCreationForm sh("shForm");
        RobotomyRequestForm rb("rbForm");
        PresidentialPardonForm pr("prForm");
        brc.executeForm(sh);
        brc.signForm(sh);
        brc.executeForm(sh);
        brc.signForm(rb);
        rb.execute(brc);//50% robotomized here
        rb.execute(brc);//50% not 
        brc.signForm(pr);
        pr.execute(brc);
        sh.execute(brc);//tree
        ///////////////// canonical form ///////////////// (check assingnements in CAO and CC!!)
        PresidentialPardonForm pr2("prfOOOORMMMMM");
        pr2 = pr;
        pr2.execute(brc);
    }
    catch(const std::exception &excp)
    {
        std::cout << excp.what() << std::endl;
    }
    return (0);
}