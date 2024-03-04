/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 22:46:59 by hlabouit          #+#    #+#             */
/*   Updated: 2024/03/04 04:35:59 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"RPN.hpp"

bool check_if_number(std::string str)
{
    std::stringstream ss(str);

    double number;
    ss >> number;
    if (ss.fail() || !ss.eof())
        throw "string stream convertion failed!";
    if (number < INT_MIN)
        throw "invalid number range!";
    return (true);
}

bool check_if_arithmetic_operator(char ao)
{
    if (ao == '+' || ao == '-'
        || ao == '*' || ao == '/' || isdigit(ao))
            return (true);
    throw "input must be composed only of digits and arithmetic operators!";
    return (false);
    
}

void parsing(std::string input)
{
    std::stringstream ss;
    ss << input;

    std::string stream_content;
    while (ss >> stream_content)
    {
        if (stream_content.length() > 1)
            check_if_number(stream_content);
        else
            check_if_arithmetic_operator(stream_content[0]);
    }
}

