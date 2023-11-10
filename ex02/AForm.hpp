/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
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
#include <cstdlib>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
	AForm();
	AForm(AForm &form);
	AForm(std::string name, int signGrade, int execGrade);
	virtual ~AForm();
	AForm &operator=(AForm &form);

	bool getIsSigned(void) const;
	const std::string getName(void) const;
	const int getSignGrade() const;
	const int getExecGrade() const;
	void beSigned(Bureaucrat &bureaucrat);
	bool canExecute(Bureaucrat const &bureaucrat) const;
	virtual void execute(Bureaucrat const & executor) const = 0;

class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "the grade is too high";
		}
	};
class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "the grade is too low";
		}
	};
class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "the form is not signed";
		}
	};

	private:
	bool isSigned;
	const std::string name;
	const int signGrade;
	const int execGrade;
};
std::ostream &operator<<(std::ostream& COUT, AForm const &form);
