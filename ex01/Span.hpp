/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:08 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/29 04:27:12 by hlabouit         ###   ########.fr       */
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
        std::vector<int>::iterator itr;
        Span();
    public:
        Span(unsigned int N);
        Span(const Span &primary);
        Span &operator=(const Span &primary);
        void addNumber(int to_add);
        int shortestSpan() const;
        int longestSpan() const;
        ~Span();
};

#endif
