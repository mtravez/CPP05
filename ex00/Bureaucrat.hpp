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

class Bureaucrat
{
	public:
	//OCF stuff
	Bureaucrat();
	Bureaucrat(Bureaucrat &bureaucrat);
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat &operator=(Bureaucrat &bureaucrat);

	//Accessors
	int getGrade() const;
	std::string getName() const;

	//Functions
	void incrementGrade(int inc);
	void decrementGrade(int dec);

	//Exceptions
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
