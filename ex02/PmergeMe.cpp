/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 22:46:59 by hlabouit          #+#    #+#             */
/*   Updated: 2024/03/05 02:51:12 by hlabouit         ###   ########.fr       */
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

void generate_combination(int unsorted_pairs_seconds_size, std::vector<int> &js_ri_combination)
{
    int js_numbers[unsorted_pairs_seconds_size];

    js_numbers[0] = 0;
    js_numbers[1] = 1;
    int limit = 2;
    
    //generate jacob sthal numbers
    for (int i = 2; i < unsorted_pairs_seconds_size; i++)
    {
        js_numbers[i] = js_numbers[i - 1] + (2 * js_numbers[i - 2]);//[2] = 1; [3] = 3
        js_ri_combination.push_back(js_numbers[i]);// 1, 3, 2
        for (int j = js_numbers[i] - 1; j > limit; j--)//j = 2; ;j > 1
            js_ri_combination.push_back(j);
        limit = js_numbers[i];// 1 3
    }
    
    // printing combination
    // for (size_t i = 0; i < js_ri_combination.size(); i++)
    //     std::cout<< js_ri_combination[i] << std::endl;

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
    std::vector<int> js_ri_combination;
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
    
    //binary search works for sorted elements  know we try to insert the unsorted sequence into the sorted one
    //print pairs
    
    for (size_t i = 0; i < Vpairs.size(); i++)
    {
        if (i == 0)
        {
            Vsorted_pairs_firsts.push_back(Vpairs[i].first);
            Vsorted_pairs_firsts.push_back(Vpairs[i].second);
        }
        else
            Vsorted_pairs_firsts.push_back(Vpairs[i].first);
        Vunsorted_pairs_seconds.push_back(Vpairs[i].second);
    }
    generate_combination(Vunsorted_pairs_seconds.size(), js_ri_combination);

    
    
    // for (size_t i = 0; i < Vsorted_pairs_firsts.size(); i++)
    // {
    //     std::cout << "sorted: " << Vsorted_pairs_firsts[i] << std::endl;
    // }
    // for (size_t i = 0; i < Vunsorted_pairs_seconds.size(); i++)
    // {
    //     std::cout << "unsorted: " << Vunsorted_pairs_seconds[i] << std::endl;
    // }

    
    
}

