/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:08 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/23 03:12:41 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>
#include<ctype.h>
#include<cstdlib>
#include<cmath>


typedef struct t_casts
{
    int int_val;
    char char_val;
    float float_val;
    double double_val;
    int flag;
    size_t position;
} t_casts;



class ScalarConverter {
    private:
        ScalarConverter();
    public:
        ScalarConverter(const ScalarConverter &primary);
        ScalarConverter &operator=(const ScalarConverter &primary);
        void pars_input(std::string input);
        static void convert(std::string input);
        ~ScalarConverter();
};

int parsing(std::string input);

#endif
