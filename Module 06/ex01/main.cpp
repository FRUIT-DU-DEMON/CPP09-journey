/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:36 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/25 01:31:27 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Serializer.hpp"

int main()
{
	Data data;
	Data *deserialize_data;
	uintptr_t serialized_data;

	data.value = 5;
	serialized_data = Serializer::serialize(&data);
	deserialize_data = Serializer::deserialize(serialized_data);

	if (deserialize_data != &data)
		std::cout<< "failed to serialize data" << std::endl;
	else
		std::cout<< "data is serialized" << std::endl;
		
	// std::cout << std::hex << serialized_data << std::endl;
	// std::cout << deserialize_data<< std::endl;
	return (0);
}
