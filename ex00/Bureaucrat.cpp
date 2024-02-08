/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:58:47 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/08 00:00:56 by hlabouit         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include"Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &primary)
{
    *this = primary;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &primary)
{
    if (this != &primary)
        this->grade = primary.grade;
    return (*this);
}

Bureaucrat::Bureaucrat(const std::string &which_name, int which_grade) : name(which_name), grade(which_grade) {}

const std::string &Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

void Bureaucrat::incrementGrade()
{
    this->grade--;
}

void Bureaucrat::decrementGrade()
{
    this->grade++;
}



Bureaucrat::~Bureaucrat() {}