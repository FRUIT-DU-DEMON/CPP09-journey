/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:36 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/23 23:45:33 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ScalarConverter.hpp"



int main(int ac, char **av)
{
    (void)ac;
    t_casts casts = float_double_to_casts(av[1]);
    std::cout<< "char: '" << casts.char_val << "'"<< std::endl;
	std::cout<< "int: " << casts.int_val << std::endl;
	std::cout<< "float: " << casts.double_val << std::endl;
	std::cout<< "double: " << casts.float_val << std::endl;
    
}