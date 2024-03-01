/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:36 by hlabouit          #+#    #+#             */
/*   Updated: 2024/03/01 05:38:37 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Span.hpp"

int main()
{
    try
    {
        Span sp = Span(500);
        
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout<< sp.shortestSpan() << std::endl;
        std::cout<< sp.longestSpan() << std::endl;
        
        std::vector<int> container;
        for (int i = 0; i < 25; i++)
            container.push_back(i);
            
        sp.insert_data(container.begin(), container.end());
        std::cout<< sp.shortestSpan() << std::endl;
        std::cout<< sp.longestSpan() << std::endl;
        
    }
    catch(const char *excp)
    {
        std::cout<< excp << std::endl;
    }
}