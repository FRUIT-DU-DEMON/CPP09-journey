/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 22:46:59 by hlabouit          #+#    #+#             */
/*   Updated: 2024/03/05 01:12:26 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PmergeMe.hpp"

double ss_to_nbr(std::string stream_contenet)
{
    std::stringstream ss(stream_contenet);

    double number;
    ss >> number;
    if (ss.fail() || !ss.eof())
        throw "string stream convertion failed!";
    if (number < 0 || number > INT_MAX)
        throw "invalid number range!";
    return (number);
}

void parsing(std::string input)
{
    if (input.empty())
        throw "empty input!";
    std::stringstream ss(input);
    std::string stream_content;
    std::vector<int> Vcontainer;
    std::vector<int> Vsorted_pairs_firsts;
    std::vector<int> Vunsorted_pairs_seconds;
    std::vector<std::pair<int, int> > Vpairs;
    int last = -1;
    
    while (ss >> stream_content)
        Vcontainer.push_back(ss_to_nbr(stream_content));
    if ((Vcontainer.size() % 2) != 0)
    {
        last = Vcontainer[Vcontainer.size() - 1];
        Vcontainer.pop_back();
    }
    //combine pairs

    for (size_t i = 0; i < Vcontainer.size(); i += 2)
    {
        if (Vcontainer[i + 1] > Vcontainer[i])
            Vpairs.push_back(std::make_pair(Vcontainer[i + 1], Vcontainer[i]));
        else
            Vpairs.push_back(std::make_pair(Vcontainer[i], Vcontainer[i + 1]));
    }
    std::sort(Vpairs.begin(), Vpairs.end());
    
    //binary search works for sorted elements !!!!!!!!!!!!!
    //print pairs
    
    for (size_t i = 0; i < Vpairs.size(); i++)
    {
        if (i == 0)
        {
            Vsorted_pairs_firsts.push_back(Vpairs[i].second);
            Vsorted_pairs_firsts.push_back(Vpairs[i].first);
        }
        else
            Vsorted_pairs_firsts.push_back(Vpairs[i].first);
        Vunsorted_pairs_seconds.push_back(Vpairs[i].second);
    }
    
    for (size_t i = 0; i < Vsorted_pairs_firsts.size(); i++)
    {
        std::cout << "sorted: " << Vsorted_pairs_firsts[i] << std::endl;
    }
    for (size_t i = 0; i < Vunsorted_pairs_seconds.size(); i++)
    {
        std::cout << "unsorted: " << Vunsorted_pairs_seconds[i] << std::endl;
    }
    
}

