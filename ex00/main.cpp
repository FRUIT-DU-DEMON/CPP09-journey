/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:36 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/28 18:51:49 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"easyfind.hpp"

int main()
{
    try
    {
        std::vector<int> data_container;
        data_container.push_back(-1137);
        data_container.push_back(10);
        data_container.push_back(20);
        data_container.push_back(30);
        data_container.push_back(40);
        data_container.push_back(50);
        data_container.push_back(1337);
        easyfind(data_container, 1337);
        
    }
    catch(const char *excp)
    {
        std::cout<< excp<< std::endl;
    }
    
}