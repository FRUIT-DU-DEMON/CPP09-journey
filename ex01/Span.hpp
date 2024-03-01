/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:08 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/29 22:47:37 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>
#include<ctype.h>
#include<cstdlib>
#include<cmath>
#include<sstream>
#include<algorithm>
#include<iterator>
#include<vector>

class Span {
    private:
        unsigned int N;
        std::vector<int> Vcontainer;
        Span();
    public:
        Span(unsigned int N);
        Span(const Span &primary);
        Span &operator=(const Span &primary);
        void addNumber(int to_add);
        int shortestSpan();
        int longestSpan();
        void insert_data(std::vector<int>::iterator itr_begin, std::vector<int>::iterator itr_end);
        ~Span();
};

#endif
