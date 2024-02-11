/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:37:34 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/11 03:16:24 by hlabouit         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include"Bureaucrat.hpp"

int main()
{
	try
    {
        Bureaucrat brcII("VanGogh", 3);
        // Bureaucrat brcIV("Prince", 1);
        // brcIV = brcII;
        Form brc_form("Visa", 4, 150);
        brc_form.beSigned(brcII);
        brcII.signForm(brc_form);
        std::cout<< brc_form << std::endl;
    }
    catch(const std::exception &excp)
    {
        std::cout << excp.what() << std::endl;
    }
}