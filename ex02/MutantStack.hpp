/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:08 by hlabouit          #+#    #+#             */
/*   Updated: 2024/03/02 00:12:39 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

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
#include<stack>
#include<deque>

template <typename T, typename CONTAINER = std::deque<T> >
class MutantStack : public std::stack<T, CONTAINER>
{
    public:
        MutantStack(){};
        MutantStack(const MutantStack &priamry)
        {
            *this = priamry;
        }
        MutantStack &operator=(const MutantStack &primary)
        {
            if (this != &primary)
                this->c = primary.c;
            return (*this);
        }
        
        typedef typename CONTAINER::iterator iterator;
        typedef typename CONTAINER::const_iterator const_iterator;
        
        iterator begin() {return (this->c.begin());}
        iterator end() {return (this->c.end());}
        const_iterator begin() const {return (this->c.begin());}
        const_iterator end() const {return (this->c.end());}
        
        ~MutantStack(){};
};

#endif
