/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 22:46:59 by hlabouit          #+#    #+#             */
/*   Updated: 2024/03/06 18:03:30 by hlabouit         ###   ########.fr       */
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

template <typename CONTAINER>
void generate_combination(int unsorted_pairs_seconds_size, CONTAINER &js_ri_combination)
{
    int js_numbers[unsorted_pairs_seconds_size + 10];
    js_numbers[0] = 0;
    js_numbers[1] = 1;
    int limit = 2;

    //generate jacob sthal numbers
    for (size_t i = 2; js_ri_combination.size() < static_cast<size_t>(unsorted_pairs_seconds_size); i++)
    {
        js_numbers[i] = js_numbers[i - 1] + (2 * js_numbers[i - 2]);//3
        js_ri_combination.push_back(js_numbers[i]);//   1 3 2
        for (int j = js_numbers[i] - 1; j > limit; j--)//20 19 18 17
        {
            js_ri_combination.push_back(j);
        }
        limit = js_numbers[i];//1
    }
}

void pop_dup(std::vector<int> &Vcontainer)
{
    for (size_t i = 0; i < Vcontainer.size(); i++)
    {
        for (size_t j = 0; j < Vcontainer.size(); j++)
        {
            if (i != j && Vcontainer[i] == Vcontainer[j])
                throw "duplicated numbers!";
        }
    }
}

long long	get_current_time()
{
	struct timeval	tv;
	long long		current_time;

	gettimeofday(&tv, NULL);
	current_time = (tv.tv_sec * 1000000) + tv.tv_usec;
	return (current_time);
}

void sort_VC(std::string input)
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
    pop_dup(Vcontainer);
    //get current time
    size_t VC_size = Vcontainer.size();
    long long time = get_current_time();
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
    
    //lower bound binary search works for sorted elements  know we try to insert the unsorted sequence into the sorted one
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
    generate_combination(Vunsorted_pairs_seconds.size() + 2, js_ri_combination);
    int value;
    for (size_t i = 0; i < Vunsorted_pairs_seconds.size(); i++)
    {
        if (js_ri_combination[i] >= static_cast<int>(Vunsorted_pairs_seconds.size()))
            js_ri_combination[i] = i;
        value = Vunsorted_pairs_seconds[js_ri_combination[i]];
        if (std::find(Vsorted_pairs_firsts.begin(),  Vsorted_pairs_firsts.end(), value) != Vsorted_pairs_firsts.end())
            continue;
        std::vector<int>::iterator itr = std::lower_bound(Vsorted_pairs_firsts.begin(), Vsorted_pairs_firsts.end(), value);
        Vsorted_pairs_firsts.insert(itr, value);
    }
    if(last != -1)
    {
        std::vector<int>::iterator itr =  std::lower_bound(Vsorted_pairs_firsts.begin(), Vsorted_pairs_firsts.end(), last);
        Vsorted_pairs_firsts.insert(itr, last);
    }
    std::cout << "Before: ";
    for (size_t i = 0; i < Vcontainer.size(); i++)
    {
        std::cout << Vcontainer[i] << " ";
    }
    if (last != -1)
        std::cout << last;
    std::cout << '\n';
    std::cout << '\n';
    std::cout << "After : ";
    for (size_t i = 0; i < Vsorted_pairs_firsts.size(); i++)
    {
        std::cout << Vsorted_pairs_firsts[i] << " ";
    }
    time = get_current_time() - time;
    std::cout << '\n';
    std::cout << "Time to process a range of " << VC_size << " elements with std::vector : " << time << " us" << std::endl;
    sort_DC(input);
}

void sort_DC(std::string input)
{
    if (input.empty())
        throw "empty input!";
    std::stringstream ss(input);
    std::string stream_content;
    std::deque<int> Dcontainer;
    std::deque<int> Dsorted_pairs_firsts;
    std::deque<int> Dunsorted_pairs_seconds;
    std::deque<int> js_ri_combination;
    std::deque<std::pair<int, int> > Dpairs;
    int last = -1;
    
    while (ss >> stream_content)
        Dcontainer.push_back(ss_to_nbr(stream_content));

    size_t DC_size = Dcontainer.size();
    long long time = get_current_time();
    if ((Dcontainer.size() % 2) != 0)
    {
        last = Dcontainer[Dcontainer.size() - 1];
        Dcontainer.pop_back();
    }
    //combine pairs

    for (size_t i = 0; i < Dcontainer.size(); i += 2)
    {
        if (Dcontainer[i + 1] > Dcontainer[i])
            Dpairs.push_back(std::make_pair(Dcontainer[i + 1], Dcontainer[i]));
        else
            Dpairs.push_back(std::make_pair(Dcontainer[i], Dcontainer[i + 1]));
    }
    std::sort(Dpairs.begin(), Dpairs.end());
    for (size_t i = 0; i < Dpairs.size(); i++)
    {
        if (i == 0)
        {
            Dsorted_pairs_firsts.push_back(Dpairs[i].second);
            Dsorted_pairs_firsts.push_back(Dpairs[i].first);
        }
        else
            Dsorted_pairs_firsts.push_back(Dpairs[i].first);
        Dunsorted_pairs_seconds.push_back(Dpairs[i].second);
    }
    generate_combination(Dunsorted_pairs_seconds.size() + 2, js_ri_combination);
    int value;
    for (size_t i = 0; i < Dunsorted_pairs_seconds.size(); i++)
    {
        if (js_ri_combination[i] >= static_cast<int>(Dunsorted_pairs_seconds.size()))
            js_ri_combination[i] = i;
        value = Dunsorted_pairs_seconds[js_ri_combination[i]];
        if (std::find(Dsorted_pairs_firsts.begin(),  Dsorted_pairs_firsts.end(), value) != Dsorted_pairs_firsts.end())
            continue;
        std::deque<int>::iterator itr =  std::lower_bound(Dsorted_pairs_firsts.begin(), Dsorted_pairs_firsts.end(), value);
        Dsorted_pairs_firsts.insert(itr, value);
    }
    if(last != -1)
    {
        std::deque<int>::iterator itr =  std::lower_bound(Dsorted_pairs_firsts.begin(), Dsorted_pairs_firsts.end(), last);
        Dsorted_pairs_firsts.insert(itr, last);
    }
    time = get_current_time() - time;
    std::cout << "Time to process a range of " << DC_size << " elements with std::deque  : " << time << " us" << std::endl;
}
