/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:50:32 by mtravez           #+#    #+#             */
/*   Updated: 2023/10/09 12:27:15 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"
# define RESET   "\x1B[0m"
# define RED     "\x1B[31m"
# define LIME    "\x1B[38;2;50;205;50m"

class Form;

class Bureaucrat
{
	public:
	Bureaucrat();
	Bureaucrat(Bureaucrat &bureaucrat);
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat &operator=(Bureaucrat &bureaucrat);
	int getGrade() const;
	std::string getName() const;
	void incrementGrade(int inc);
	void decrementGrade(int dec);
	void signForm(Form &form);
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
	const std::string name;
	int grade;
};
std::ostream &operator<<(std::ostream& COUT, Bureaucrat const &bureaucrat);
