/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:52:56 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/11 00:14:35 by hlabouit         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include"Form.hpp"

Form::Form() : name("form"), if_signed(false), grade_sg(150), grade_ex(150)
{
}

Form::Form(const std::string &which_name, int which_grade_sg, int which_grade_ex) : name(which_name), if_signed(false), grade_sg(which_grade_sg), grade_ex(which_grade_ex)
{
	if (which_grade_ex > 150 || which_grade_sg > 150)
		throw Bureaucrat::GradeTooLowException();
	if (which_grade_ex < 1 || which_grade_sg < 1)
		throw Bureaucrat::GradeTooHighException();
}

Form::Form(const Form &primary) : name(primary.name), if_signed(primary.if_signed), grade_sg(primary.grade_sg), grade_ex(primary.grade_ex)
{
}

Form &Form::operator=(const Form &primary)
{
	if (this != &primary)
		this->if_signed = primary.if_signed;
	return (*this);
}

const std::string &Form::getName() const
{
	return (this->name);
}

int Form::getGrade_sg() const
{
	return (this->grade_sg);
}

int Form::getGrade_ex() const
{
	return (this->grade_ex);
}

void Form::beSigned(const Bureaucrat &brc)
{
	if (brc.getGrade() <= this->grade_sg)
		this->if_signed = true;
	else 
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &output_console, const Form &brc_form)
{
	// output_console << 
	return (output_console);
}

Form::~Form()
{
}