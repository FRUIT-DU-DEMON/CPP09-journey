/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverte.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:08 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/23 22:34:30 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ScalarConverter.hpp"

int parsing(std::string input)
{
	int i = 0;
	int sign_flag = 0;
	int fractional_flag = 0;
	int precision_flag = 0;
    int len = input.length();
    
	while (i < len)
	{
		if ((input[i] >= '0' && input[i] <= '9') || input[i] == '.' || input[i] == 'f'
			|| input[i] == '+' || input[i] == '-')
        {
            if (input[i] == '.')
            {
            if (!(input[i + 1] >= '0' && input[i + 1] <= '9')
                || !(input[i - 1] >= '0' && input[i - 1] <= '9'))
                    return (-1);
                fractional_flag++;
            }
            if (input[i] == '+' || input[i] == '-')
                sign_flag++;
            if (input[i] == 'f')
            {
                if (fractional_flag != 1)
                    return (-1);
                precision_flag++;
            }
            if (sign_flag > 1 || fractional_flag > 1 || precision_flag > 1)
                return (-1);
        }
        else
            return (-1);
		i++;
	}
	return (1);
}

t_casts char_to_casts(std::string &input)
{
	t_casts casts;
	
	if (input.length() == 1)
	{
		if (input[0] >= 32 && input[0] < 127)
		{
			casts.char_val = input[0];
			casts.int_val = static_cast<int>(input[0]);
			casts.float_val = static_cast<float>(input[0]);
			casts.double_val = static_cast<double>(input[0]);
			casts.flag = 1;
			return (casts);
		}
		else
			casts.non_dsp = true;
	}
	casts.flag = -1;
	return (casts);
}


t_casts float_double_to_casts(std::string &input)
{
	t_casts casts;
	std::stringstream ss;

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == '.')
		{
			if (input[input.length() - 1] == 'f')
			{
				ss << input;
				ss >> casts.float_val;
				casts.int_val = static_cast<int>(casts.float_val);
				casts.double_val = static_cast<double>(casts.float_val);
				if (casts.int_val >= 32 && casts.int_val < 127)
					casts.char_val = static_cast<char>(casts.float_val);
				else
					casts.non_dsp = true;
				casts.flag = 1;
				return (casts);
			}
			else
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
	}
	casts.flag = -1;
	return (casts);
}


void impossible()
{
	std::cout<< "char: impossible" << std::endl;
	std::cout<< "int: impossible" << std::endl;
	std::cout<< "float: impossible" << std::endl;
	std::cout<< "double: impossible" << std::endl;
}