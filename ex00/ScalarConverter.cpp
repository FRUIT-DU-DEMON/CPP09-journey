/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:08 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/24 04:54:23 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ScalarConverter.hpp"

int parsing(std::string input)
{
	std::stringstream ss;
	double prs;
	
	if (input.length() == 1)
		return (0);
	if (input[input.length() - 1] == 'f')
		input = input.substr(0, input.length() - 1);
	ss << input;
	ss >> prs;
	if (ss.fail() || !ss.eof()) // protection if there's a type mismatch or (digits/chars)
	{
		std::cout<< "char: " << "impossible" << std::endl;
		std::cout<< "int: " << "impossible" << std::endl;
		std::cout<< "float: " << "nanf" << std::endl;
		std::cout<< "double: " << "nan" << std::endl;
		return (-1);
	}
	return (0);
}

t_casts char_to_casts(std::string input)
{
	t_casts casts;
	
	if (input.length() == 1)
	{
		std::stringstream ss;
		ss << input;
		ss >> casts.char_val;
		// if (ss.fail() || !ss.eof())
		// {
		// 	casts.flag = -1;
		// 	return (casts);
		// }
		puts("WEFDwef");
		if (casts.char_val >= 32 && casts.char_val < 127)
		{
			casts.char_val = casts.char_val;
			casts.int_val = static_cast<int>(casts.char_val);
			casts.float_val = static_cast<float>(casts.char_val);
			casts.double_val = static_cast<double>(casts.char_val);
			casts.flag = 1;
			return (casts);
		}
		else
			casts.non_dsp = true;
	}
	casts.flag = -1;
	return (casts);
}

t_casts float_double_to_casts(std::string input)
{
	t_casts casts;
	std::stringstream ss;
	double overflow;
    int len = input.length();

	for (int i = 0; i < len; i++)
	{
		if (input[input.length() - 1] == 'f')
		{
			input = input.substr(0, input.length() - 1);
			ss << input;
			ss >> casts.float_val;
			ss >> overflow;
			casts.int_val = overflow;
			if (overflow < INT_MIN || overflow > INT_MAX)
			{
				casts.float_val = static_cast<float>(overflow);
				casts.double_val = static_cast<double>(overflow);
				display_casts(casts, true, -1);
				return (casts);
			}
			casts.int_val = static_cast<int>(casts.float_val);
			casts.double_val = static_cast<double>(casts.float_val);
			if (casts.int_val >= 32 && casts.int_val < 127)
				casts.char_val = static_cast<char>(casts.float_val);
			else
				casts.non_dsp = true;
			casts.flag = 1;
			return (casts);
		}
		else if (input[i] == '.')
		{
			ss << input;
			ss >> casts.double_val;
			casts.int_val = static_cast<int>(casts.double_val);
			casts.float_val = static_cast<float>(casts.double_val);
			if (casts.int_val >= 32 && casts.int_val < 127)
				casts.char_val = static_cast<char>(casts.double_val);
			else
				casts.non_dsp = true;
			casts.flag = 1;
			return (casts);
		}
	}
	casts.flag = -1;
	return (casts);
}

t_casts int_to_casts(std::string input)
{
	t_casts casts;
	std::stringstream ss;
	double overflow;

	ss << input;
	ss >> overflow;
	if (ss.fail() || !ss.eof())
	{
		casts.flag = -1;
		return (casts);
	}
	casts.int_val = overflow;
	if (overflow < INT_MIN || overflow > INT_MAX)
	{
		casts.float_val = static_cast<float>(overflow);
		casts.double_val = static_cast<double>(overflow);
		display_casts(casts, true, -1);
		return (casts);
	}
	if (casts.int_val >= 32 && casts.int_val < 127)
		casts.char_val = static_cast<char>(casts.int_val);
	else
		casts.non_dsp = true;
	casts.float_val = static_cast<float>(casts.int_val);
	casts.double_val = static_cast<double>(casts.int_val);
	casts.flag = 1;
	return (casts);
}

void display_casts(t_casts casts, bool non_dsp, int overflow)
{
	if (overflow == -1)
	{
		std::cout<< "char: " << "Non displayable" << std::endl;
		std::cout<< "int: " << "impossible" << std::endl;
		std::cout<< "float: " << casts.float_val << std::endl;
		std::cout<< "double: " << casts.double_val << std::endl;
	}
	else if (non_dsp == true)
	{
		std::cout<< "char: " << "Non displayable" << std::endl;
		std::cout<< "int: " << casts.int_val << std::endl;
		std::cout<< "float: " << casts.float_val << ".0f" << std::endl;
		std::cout<< "double: " << casts.double_val << ".0" << std::endl;
	}
	else 
	{
		std::cout<< "char: '" << casts.char_val << "'" << std::endl;
		std::cout<< "int: " << casts.int_val << std::endl;
		std::cout<< "float: " << casts.float_val << ".0f" << std::endl;
		std::cout<< "double: " << casts.double_val << ".0" << std::endl;
	}
}

void ScalarConverter::convert(std::string input)
{
	t_casts casts;
	
	if (float_double_to_casts(input).flag == 1)
	{
		casts = float_double_to_casts(input);
		if (casts.non_dsp == true)
			display_casts(casts, true, 1);
		else
			display_casts(casts, false, 1);
	}
	else if (int_to_casts(input).flag == 1)
	{
		casts = int_to_casts(input);
		if (casts.non_dsp == true)
			display_casts(casts, true, 1);
		else
			display_casts(casts, false, 1);
	}
	else if (char_to_casts(input).flag == 1)
	{
		casts = char_to_casts(input);
		if (casts.non_dsp == true)
			display_casts(casts, true, 1);
		else
			display_casts(casts, false, 1);
	}
	return;
}