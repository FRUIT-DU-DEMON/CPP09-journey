/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:36 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/24 22:26:41 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Serializer.hpp"

int main()
{
	char* ch = new char('G');
	int* p = reinterpret_cast<int *>(ch);
	std::cout << *p << std::endl;
	std::cout << *ch << std::endl;
	std::cout << p << std::endl;
	std::cout << ch << std::endl;
	return 0;
}
