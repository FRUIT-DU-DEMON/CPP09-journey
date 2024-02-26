/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:08 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/26 03:25:46 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>
#include<ctype.h>
#include<cstdlib>
#include<cmath>
#include<sstream>

template <typename TYPE, typename TYPE2>
void iter(TYPE *array, int array_length, TYPE2 called_on_elements)
{
    for (int i = 0; i < array_length; i++)
        called_on_elements(array[i], i);
}

template <typename TYPE>
void display(TYPE &element, int index)
{
    std::cout<< "element of index " << index << ": "<< element << std::endl;
}

#endif
