/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:46:46 by hlabouit          #+#    #+#             */
/*   Updated: 2024/02/07 23:23:15 by hlabouit         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>
#include<ctype.h>
#include<cstdlib>
#include<cmath>

class Bureaucrat {
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &primary);
		Bureaucrat &operator=(const Bureaucrat &primary);
		std::string getName() const;
		int getGrade() const;
        void incrementGrade();
        void decrementGrade();
		~Bureaucrat();
};

#endif
