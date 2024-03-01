/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:36 by hlabouit          #+#    #+#             */
/*   Updated: 2024/03/02 00:09:32 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"MutantStack.hpp"

int main()
{
    MutantStack<int> Ccontainer;

    for (int i = 0; i <= 100; i += 10)
        Ccontainer.push(i);
    
    MutantStack<int>::iterator itr = Ccontainer.begin();
    for (int i = 0; itr != Ccontainer.end(); i += 1)
        std::cout<< *itr++ << std::endl;
    
    // MutantStack<int>::const_iterator c_itr = Ccontainer.begin();
    // *c_itr = 500;
    
    // std::cout<< *c_itr << std::endl;
    // MutantStack<int> mstack;
    // mstack.push(5);
    // mstack.push(17);
    // std::cout << mstack.top() << std::endl;
    // mstack.pop();
    // std::cout << mstack.size() << std::endl;
    // mstack.push(3);
    // mstack.push(5);
    // mstack.push(737);
    // //[...]
    // mstack.push(0);
    // MutantStack<int>::iterator it = mstack.begin();
    // MutantStack<int>::iterator ite = mstack.end();
    // ++it;
    // --it;
    // while (it != ite)
    // {
    // std::cout << *it << std::endl;
    // ++it;
    // }
    MutantStack<int>::iterator s_itr = Ccontainer.begin();
    std::stack<int> s(Ccontainer);
    for (int i = 0; s_itr != Ccontainer.end(); i += 1)
        std::cout<< *s_itr++ << std::endl;
    
    return 0;
}