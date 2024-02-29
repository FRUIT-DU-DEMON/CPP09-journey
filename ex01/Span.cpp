/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:36 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/29 03:16:17 by hlabouit         ###   ########.fr       */
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
        throw "Vcontainer has reached it's capacity";
    this->Vcontainer.push_back(to_add);
}


