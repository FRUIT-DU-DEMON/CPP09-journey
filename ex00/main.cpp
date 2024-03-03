/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:36 by hlabouit          #+#    #+#             */
/*   Updated: 2024/03/03 21:14:38 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout<< "invalid number of arguments" << std::endl;
		exit(EXIT_FAILURE);
	}
	BitcoinExchange obj;
	obj.insert_key_val_in_MC();
	obj.read_input_file(av[1]);
}