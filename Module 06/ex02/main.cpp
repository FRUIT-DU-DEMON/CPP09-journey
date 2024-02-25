/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:36 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/25 01:45:29 by hlabouit         ###   ########.fr       */
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
    return (NULL);
}

void identify(Base* p)
{
    /*dynamic_cast only used for performing safe downcasting of pointers or references in polymorphic class
    where it converts a base class pointer or reference to a derived class pointer or reference*/
    if (dynamic_cast<A *>(p) != NULL)
        std::cout<< "the actual type of the object pointed to by p is: A" << std::endl;
    else if (dynamic_cast<B *>(p) != NULL)
        std::cout<< "the actual type of the object pointed to by p is: B" << std::endl;
    else if (dynamic_cast<C *>(p) != NULL)
        std::cout<< "the actual type of the object pointed to by p is: C" << std::endl;
    else
        std::cout<< "dynamic_cast failed to downcasts";
    return;
}

void identify(Base& p)
{
    try
    {
        Base &ref = dynamic_cast<A &>(p);
        (void)ref;
        std::cout<< "the actual type of the object pointed to by p is: A" << std::endl;
    }
    catch(const std::exception &excp)
    {
        std::cout<< excp.what() << std::endl;
    }
    try
    {
        Base &ref = dynamic_cast<B &>(p);
        (void)ref;
        std::cout<< "the actual type of the object pointed to by p is: B" << std::endl;
    }
    catch(const std::exception &excp)
    {
        std::cout<< excp.what() << std::endl;
    }
    try
    {
        Base &ref = dynamic_cast<C &>(p);
        (void)ref;
        std::cout<< "the actual type of the object pointed to by p is: C" << std::endl;
    }
    catch(const std::exception &excp)
    {
        std::cout<< excp.what() << std::endl;
    }
}

int main()
{
    std::srand(std::time(NULL));
    Base *base_ptr = generate();
    if (!base_ptr)
        return (0);
    identify(base_ptr);
    identify(*base_ptr);
    delete base_ptr;
    return (0);
}
