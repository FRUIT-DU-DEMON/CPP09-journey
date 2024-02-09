/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:58:47 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/09 22:19:22 by hlabouit         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include"Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string &which_name, int which_grade) : name(which_name), grade(which_grade)
{
    if (which_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (which_grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

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
    if (this->grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;//before or after throwing an excp!!
    // std::cout<< "HEEEREERRERERE" << std::endl;
}

void Bureaucrat::decrementGrade()
{
    if (this->grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

std::ostream &operator<<(std::ostream &output_console, const Bureaucrat &brc)
{
    output_console << brc.getName() << ", bureaucrat grade " << brc.getGrade() << ".";
    return (output_console);
}

Bureaucrat::~Bureaucrat()
{
}