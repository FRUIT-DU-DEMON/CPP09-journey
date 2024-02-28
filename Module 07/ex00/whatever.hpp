/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:08 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/25 23:49:47 by hlabouit         ###   ########.fr       */
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

/*templates are a powerful feature that allow you to write generic code
 template is a blueprint for a piece of code that can work with any data type*/
 
template <typename TYPE>//The compiler will generate code for a function that deals with the specified type
void swap(TYPE &a, TYPE &b)
{
    TYPE tmp = a;
    a = b;
    b = tmp;
}

template <typename TYPE>
TYPE min(TYPE a, TYPE b)
{
    if (a < b)
        return (a);
    if (b < a)
        return (b);
    return (b);
}

template <typename TYPE>
TYPE max(TYPE a, TYPE b)
{
    if (a > b)
        return (a);
    if (b > a)
        return (b);
    return (b);
}

#endif
