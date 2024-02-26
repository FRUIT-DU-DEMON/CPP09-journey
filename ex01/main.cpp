/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:36 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/26 02:08:00 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"iter.hpp"

int main()
{
    std::string array[] = {"CASA", "TO", "LAGOS"};
    
    iter(array, 3, called_on_elements<std::string>);
    
    return (0);
}