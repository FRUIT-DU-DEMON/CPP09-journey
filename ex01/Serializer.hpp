/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:08 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/24 20:09:53 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
# define SERIALIZER_H

#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>
#include<ctype.h>
#include<cstdlib>
#include<cmath>
#include<sstream>

typedef struct Data
{
    int data1;
} Data;

/*Serialization in C++ refers to the process of converting objects or data structures
 into a format that can be easily stored, transmitted, or reconstructed, and this operation
 involves converting the internal state of an object into a stream of bytes
 Serialized objects can be sent between different processes or even different machines over a network*/
class Serializer {
    private:
        Serializer();
    public:
        Serializer(const Serializer &primary);
        Serializer &operator=(const Serializer &primary);
        uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);
        ~Serializer();
};

#endif
