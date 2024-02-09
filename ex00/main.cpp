/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:37:34 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/09 22:23:18 by hlabouit         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include"Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat brc("IVXX", 1);
		std::cout << brc << std::endl;
		brc.incrementGrade();
		std::cout << brc << std::endl;//won't be executed because an excp's been thrown
	}
	catch(const std::exception &excp)//any exception derived from std::exception thrown get caught 
	{
		std::cout << excp.what() << std::endl;
	}
	return (0);
}