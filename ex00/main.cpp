/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:36 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/23 03:28:55 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ScalarConverter.hpp"


int main(int ac, char **av)
{
    (void)ac;
	int i = parsing(av[1]);
    std::cout<< i << std::endl;
}