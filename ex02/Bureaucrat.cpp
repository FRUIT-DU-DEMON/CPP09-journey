/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:58:47 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/14 02:44:11 by hlabouit         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include"Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("brc"), grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string &which_name, int which_grade) : name(which_name), grade(which_grade)
{
	if (which_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (which_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &primary) : name(primary.name), grade(primary.grade)
{
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

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);//exception is thrown here
		std::cout<< this->name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception &excp)
	{
		std::cout<< this->name << " couldn’t sign " << form.getName() << " because its " << excp.what() << std::endl;//to output the reason here
	}
}

std::ostream &operator<<(std::ostream &output_console, const Bureaucrat &brc)
{
	output_console << brc.getName() << ", bureaucrat grade " << brc.getGrade() << ".";
	return (output_console);
}

Bureaucrat::~Bureaucrat()
{
}