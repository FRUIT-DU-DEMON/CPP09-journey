/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:08 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/18 19:31:59 by hlabouit         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/



#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>
#include<ctype.h>
#include<cstdlib>
#include<cmath>

class ScalarConverter {
    private:
        ScalarConverter();
    public:
        ScalarConverter(const ScalarConverter &primary);
        ScalarConverter &operator=(const ScalarConverter &primary);
        static void convert(std::string input);
        ~ScalarConverter();
};





#endif
