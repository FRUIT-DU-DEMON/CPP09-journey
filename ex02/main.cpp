/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:37:34 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/15 04:37:39 by hlabouit         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include"Bureaucrat.hpp"
#include"ShrubberyCreationForm.hpp"

int main()
{
	try
    {
        Bureaucrat brc("vanGogh", 1);
        ShrubberyCreationForm sh("tst");
        brc.signForm(sh);
        sh.execute(brc);
    }
    catch(const std::exception &excp)
    {
        std::cout << excp.what() << std::endl;
    }
    return (0);
}