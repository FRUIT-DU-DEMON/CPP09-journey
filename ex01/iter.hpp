/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:08 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/26 02:07:29 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
# define WHATEVER_H

#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>
#include<ctype.h>
#include<cstdlib>
#include<cmath>
#include<sstream>

template <typename TYPE, typename FUNC>
void iter(TYPE *array, int array_length, FUNC called_on_elements)
{
    for (int i = 0; i < array_length; i++)
        called_on_elements(array[i], i);
    
}

template <typename TYPE>
void called_on_elements(TYPE element, int index)
{
    std::cout<< "element of index " << index << ": "<< element << std::endl;
    index++;
}

#endif
