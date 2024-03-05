/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:08 by hlabouit          #+#    #+#             */
/*   Updated: 2024/03/05 22:13:45 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
# define PMERGEME_H

#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>
#include<ctype.h>
#include<cstdlib>
#include<cmath>
#include<sstream>
#include<algorithm>
# include<sys/time.h>
#include<iterator>
#include<vector>
#include<stack>
#include<map>


double ss_to_nbr(std::string stream_contenet);
void generate_combination(int unsorted_pairs_seconds_size, std::vector<int> &js_ri_combination);
void pop_dup(std::vector<int> &Vcontainer);
void sort_VC(std::string input);
void sort_DC(std::string input);


#endif
