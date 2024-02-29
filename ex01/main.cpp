/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:36 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/29 22:44:59 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Span.hpp"

int main()
{
    try
    {
        Span obj(100);
        // obj.insert_data(0, 99);
        obj.addNumber(6);
        obj.addNumber(3);
        obj.addNumber(17);
        obj.addNumber(9);
        obj.addNumber(11);
        obj.addNumber(11);
        obj.addNumber(11);
        obj.addNumber(11);
        std::cout<< obj.shortestSpan() << std::endl;
        // std::cout<< obj.longestSpan() << std::endl;
        // obj.shortestSpan();
        
    }
    catch(const char *excp)
    {
        std::cout<< excp << std::endl;
    }
}