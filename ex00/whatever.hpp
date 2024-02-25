/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:08 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/25 21:45:44 by hlabouit         ###   ########.fr       */
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

template <typename TYPE>
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
