/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:36 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/22 04:31:55 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ScalarConverter.hpp"


t_casts char_to_casts(std::string input)
{
    t_casts casts;
    
    if (input.length() == 1 && input[0] >= 0 && input[0] <= 127)
    {
        casts.int_val = static_cast<int>(input[0]);
        casts.float_val = static_cast<float>(input[0]);
        casts.double_val = static_cast<double>(input[0]);
    }
    return (casts);
}



int main(int ac, char **av)
{
    (void)ac;
	t_casts casts = char_to_casts(av[1]);
    std::cout<< casts.int_val << std::endl;
    std::cout<< casts.float_val <<  ".0f"<< std::endl;
    std::cout<< casts.double_val<< ".0" << std::endl;
}