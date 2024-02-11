/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:37:34 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/11 04:05:47 by hlabouit         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include"Bureaucrat.hpp"

int main()
{
	try
    {
        Bureaucrat brcII("VanGogh", 1);
        // Bureaucrat brcIV("Prince", 1);
        // brcIV = brcII;
        Form brc_form("Visa", 4, 3);
        // brc_form.beSigned(brcII);
        std::cout<< brc_form << std::endl;
        brcII.signForm(brc_form);
    }
    catch(const std::exception &excp)
    {
        std::cout << excp.what() << "dial l grade "<< std::endl;
    }
}