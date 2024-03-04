/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:08 by hlabouit          #+#    #+#             */
/*   Updated: 2024/03/04 04:29:40 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
# define RPN_H

#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>
#include<ctype.h>
#include<cstdlib>
#include<cmath>
#include<sstream>
#include<algorithm>
#include<iterator>
#include<vector>
#include<map>
 
void parsing(std::string input);
bool check_if_arithmetic_operator(char ao);
bool check_if_number(std::string str);

#endif
