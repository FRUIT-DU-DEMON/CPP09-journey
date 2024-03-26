/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 22:46:59 by hlabouit          #+#    #+#             */
/*   Updated: 2024/03/05 23:04:08 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"RPN.hpp"

bool check_if_number(std::stack<double> &Scontainer, std::string &stream_content)
{
    std::stringstream ss(stream_content);

    double number;
    ss >> number;
    if (ss.fail() || !ss.eof())
        throw "string stream convertion failed!";
    if (number < INT_MIN || number > 9)
        throw "invalid number range!";
    Scontainer.push(number);
    return (true);
}

bool check_if_arithmetic_operator(char ao)
{
    if (ao == '+' || ao == '-'
        || ao == '*' || ao == '/')
            return (true);
    throw "input must be composed only of digits and arithmetic operators!";
    return (false);
    
}

void RPN(std::string input)
{
    if (input.empty())
        throw "empty input!";
    std::stringstream ss;
    std::stack<double> Scontainer;
    ss << input;

    std::string stream_content;
    while (ss >> stream_content)
    {
        if (stream_content.length() > 1 || isdigit(stream_content[0]))
            check_if_number(Scontainer, stream_content);
        else
        {
            check_if_arithmetic_operator(stream_content[0]);
            if (Scontainer.size() < 2)
                        throw "invalid RPN!";
                int b = Scontainer.top();
                Scontainer.pop();
                int a = Scontainer.top();
                Scontainer.pop();
                if (stream_content[0] == '+')
                    Scontainer.push(a + b);
                if (stream_content[0] == '-')
                    Scontainer.push(a - b);
                if (stream_content[0] == '*')
                    Scontainer.push(a * b);
                if (stream_content[0] == '/')
                {
                    if (b == 0)
                        throw "impossible to devise on 0!";
                    Scontainer.push(a / b);
                }
        }
    }
    if (Scontainer.size() > 1)
            throw "operator is missing!";
    int res = Scontainer.top();
    std::cout<< res << std::endl;
}
