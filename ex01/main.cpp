/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:36 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/24 21:03:57 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Serializer.hpp"

// CPP program to demonstrate working of 
// reinterpret_cast
#include <iostream>
using namespace std;

int main()
{
	char* ch = new char('G');
	int* p = reinterpret_cast<int *>(ch);
	cout << *p << endl;
	cout << *ch << endl;
	cout << p << endl;
	cout << ch << endl;
	return 0;
}
