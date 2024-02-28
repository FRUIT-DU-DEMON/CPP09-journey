/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:08 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/28 21:31:46 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

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

template <typename T>
void easyfind(T &container, int to_find)
{
    typename T::iterator itr;
    for (itr = container.begin(); itr < container.end(); itr++)
    {
        if (*itr == to_find)
        {
            std::cout<< "value was found within the container: " << to_find << std::endl;
            return;
        }
    }
    throw ("value was NOT found within the container!");
}


#endif
