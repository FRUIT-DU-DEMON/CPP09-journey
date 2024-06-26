/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:36 by hlabouit          #+#    #+#             */
/*   Updated: 2024/03/05 22:13:53 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout<< "invalid number of arguments" << std::endl;
        exit(EXIT_FAILURE);
    }
    try
    {
        sort_VC(av[1]);
    }
    catch(const char *excp)
    {
        std::cout<< excp << std::endl;
    }
}