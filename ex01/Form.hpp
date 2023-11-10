/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:50:32 by mtravez           #+#    #+#             */
/*   Updated: 2023/10/17 13:06:37 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
	Form();
	Form(Form &form);
	Form(std::string name, int signGrade, int execGrade);
	~Form();
	Form &operator=(Form &form);

	bool getIsSigned(void) const;
	const std::string getName(void) const;
	const int getSignGrade() const;
	const int getExecGrade() const;
	void beSigned(Bureaucrat &bureaucrat);

class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "GradeTooHighException: the grade given is too high";
		}
	};
class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "GradeTooLowException: the grade given is too low";
		}
	};
	
	private:
	bool isSigned;
	const std::string name;
	const int signGrade;
	const int execGrade;
};
std::ostream &operator<<(std::ostream& COUT, Form const &form);
