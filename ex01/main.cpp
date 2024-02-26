/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:36 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/26 15:49:16 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"iter.hpp"

int main()
{
    std::string array1[3] = {"CASA", "TO", "LAGOS"};
    iter(array1, 3, display<std::string>);
    
    std::cout<< std::endl;

    int array2[3] = {100, 500, 1000};
    iter(array2, 3, display<int>);
    
    std::cout<< std::endl;
    
    double array3[3] = {1.1, 1.2, 1.3};
    iter(array3, 3, display<double>);
    
    return (0);
}