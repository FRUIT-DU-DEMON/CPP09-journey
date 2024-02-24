/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:36 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/24 16:35:01 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
	{
		std::cout<< "bad arguments!" << std::endl;
		return (0);
	}
	if (parsing(av[1]) == -1)
		return (0);
	ScalarConverter::convert(av[1]);
}