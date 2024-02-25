/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:36 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/25 01:22:25 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Base.hpp"
#include"A.hpp"
#include"B.hpp"
#include"C.hpp"

Base *generate(void)
{
    int random = std::rand() % 3;
    if (random == 0)
        return (new A());
    else if (random == 1)
        return (new B());
    if (random == 2)
        return (new C());
}

void identify(Base* p)
{
    /*dynamic_cast only used for performing safe downcasting of pointers or references in polymorphic class
    where it converts a base class pointer or reference to a derived class pointer or reference*/
    if (dynamic_cast<A *>(p) != NULL)
        std::cout<< "the actual type of the object pointed to by p is: A";
    else if (dynamic_cast<B *>(p) != NULL)
        std::cout<< "the actual type of the object pointed to by p is: B";
    else if (dynamic_cast<C *>(p) != NULL)
        std::cout<< "the actual type of the object pointed to by p is: C";
    else
        std::cout<< "dynamic_cast failed to downcasts";
}

void identify(Base& p)
{
    try
    {
        dynamic_cast<A &>(p);
    }
    catch(const std::exception &excp)
    {
        std::cout<< excp.what() << std::endl;
    }
    try
    {
        dynamic_cast<B &>(p);
    }
    catch(const std::exception &excp)
    {
        std::cout<< excp.what() << std::endl;
    }
    try
    {
        dynamic_cast<C &>(p);
    }
    catch(const std::exception &excp)
    {
        std::cout<< excp.what() << std::endl;
    }
}

int main()
{

    std::srand(std::time(NULL));
    // std::cout<< p << std::endl;

}
