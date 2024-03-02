/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:36 by hlabouit          #+#    #+#             */
/*   Updated: 2024/03/02 00:35:43 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Span.hpp"

Span::Span()
{
}

Span::Span(unsigned int N) : N(N)
{
}

Span::Span(const Span &primary)
{
    *this = primary;
}

Span &Span::operator=(const Span &primary)
{
    if (this != &primary)
    {
        this->N = primary.N;
        this->Vcontainer = primary.Vcontainer;
    }
    return (*this);
}

void Span::addNumber(int to_add)
{
    if (this->Vcontainer.size() == N)
        throw "couldn't addNumber: Vcontainer has reached it's capacity!";
    this->Vcontainer.push_back(to_add);
}

int Span::shortestSpan()
{
    if (this->Vcontainer.size() <= 1)
        throw "Vcontainer contains one number or none!";
    std::sort(this->Vcontainer.begin(), this->Vcontainer.end());
    int shortest_span = this->Vcontainer[1] - this->Vcontainer[0];
    for (size_t i = 0; i < this->Vcontainer.size() - 1; i++)
    {
        if ((this->Vcontainer[i + 1] - this->Vcontainer[i]) < shortest_span)
            shortest_span = this->Vcontainer[i + 1] - this->Vcontainer[i];
    }
    return (shortest_span);
}

int Span::longestSpan()
{
    if (this->Vcontainer.size() <= 1)
        throw "Vcontainer contains one number or none!";
    std::sort(this->Vcontainer.begin(), this->Vcontainer.end());
    int longest_span = this->Vcontainer[(this->Vcontainer.size() - 1)] - this->Vcontainer[0];
    return(longest_span);
}

void Span::insert_data(std::vector<int>::iterator itr_begin, std::vector<int>::iterator itr_end)
{
    if (itr_end - itr_begin < 0)
        throw "invalid range itarators!";
    if ((this->Vcontainer.size() + (itr_end - itr_begin)) > N)
        throw "couldn't insert data: Vcontainer has reached it's capacity!";
    this->Vcontainer.insert(this->Vcontainer.end(), itr_begin, itr_end);
}

Span::~Span()
{
}
