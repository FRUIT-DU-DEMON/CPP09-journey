/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:36 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/28 23:08:36 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"easyfind.hpp"

int main()
{
    try
    {
        //vector container
        std::vector<int> Vcontainer;
        Vcontainer.push_back(1);
        Vcontainer.push_back(2);
        Vcontainer.push_back(3);
        easyfind(Vcontainer, 3);
        easyfind(Vcontainer, 100);
        
        //deque container
        std::deque<double> Dcontainer;
        Dcontainer.push_back(11);
        Dcontainer.push_back(22);
        Dcontainer.push_front(33);
        // Dcontainer.pop_front();
        // Dcontainer.pop_back();
        easyfind(Dcontainer, 11);
    }
    catch(const char *excp)
    {
        std::cout<< excp<< std::endl;
    }
}