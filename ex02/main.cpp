/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:37:34 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/16 00:54:29 by hlabouit         ###   ########.fr       */
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
        ShrubberyCreationForm sh("tst");
        RobotomyRequestForm rb("tst2");
        PresidentialPardonForm pr("tst3");
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