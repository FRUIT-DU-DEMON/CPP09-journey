/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:08 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/24 04:03:05 by hlabouit         ###   ########.fr       */
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
#include<sstream>

typedef struct t_casts
{
    int int_val;
    char char_val;
    float float_val;
    double double_val;
    bool non_dsp;
    int flag;
} t_casts;

class ScalarConverter {
    private:
        ScalarConverter();
    public:
        ScalarConverter(const ScalarConverter &primary);
        ScalarConverter &operator=(const ScalarConverter &primary);
        static void convert(std::string input);
        ~ScalarConverter();
};

int     parsing(std::string input);
t_casts char_to_casts(std::string input);
t_casts float_double_to_casts(std::string input);
t_casts int_to_casts(std::string input);
void    display_casts(t_casts casts, bool non_dsp, int overflow);

#endif
