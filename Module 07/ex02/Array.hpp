/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:08 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/26 19:48:58 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>
#include<ctype.h>
#include<cstdlib>
#include<cmath>
#include<sstream>

/*class template is a way to define a generic class that can work with different data types.
it allows you to define a blueprint for a class without specifying the actual data type it will operate on.
Instead, you define placeholders for data types and use these placeholders throughout the class definition*/
template <typename T>
class Array {
    private:
        T *array;
        int arr_size;
    public:
        Array();
        Array(const Array<T> &primary);
        Array &operator=(const Array<T> &primary);
        T &operator[](int index) const;
        int size() const;
        Array(unsigned int n);
        ~Array();
};

template <typename T>
Array<T>::Array()
{
    this->array = NULL;
    this->arr_size = 0;
}

template <typename T>
Array<T>::Array(const Array<T> &primary)
{
    //can't trigger CAO could miss allocate at the right time
    this->arr_size = primary.arr_size;
    this->array = new T[primary.arr_size];
    for (int i = 0; i < primary.arr_size; i++)
        this->array[i] = primary.array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &primary)
{
    if (this != &primary)
    {
        if (this->array)
            delete[] this->array;
        this->array = new T[this->arr_size];
        this->arr_size = primary.arr_size;
        for (int i = 0; i < primary.arr_size; i++)
            this->array[i] = primary.array[i];
    }
    return (*this);
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    this->array = new T[n];
    this->arr_size = n;
    for (int i = 0; i < arr_size; i++)
        this->array[i] = T();
}

template <typename T>
T &Array<T>::operator[](int index) const
{
    if (index < 0 || index >= this->arr_size)
        throw std::out_of_range("invalid index");
    return (this->array[index]);
}

template <typename T>
int Array<T>::size() const
{
    return (this->arr_size);
}

template <typename T>
Array<T>::~Array()
{
    delete[] this->array;
}

#endif
