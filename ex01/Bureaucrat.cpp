/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:59:49 by mtravez           #+#    #+#             */
/*   Updated: 2023/10/09 13:44:05 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
	return;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade > 150)
		throw(GradeTooLowException());
	if (grade <= 0)
		throw(GradeTooHighException());
	this->grade = grade;
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat &bureaucrat) : name(bureaucrat.name), grade(bureaucrat.grade)
{
	return;
}

Bureaucrat::~Bureaucrat()
{
	return;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &bureaucrat)
{
	this->grade = bureaucrat.grade;
	return *this;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

void	Bureaucrat::incrementGrade(int inc)
{
	if (grade - inc < 1)
		throw(GradeTooHighException());
	grade -= inc;
}

void Bureaucrat::decrementGrade(int dec)
{
	if (grade + dec > 150)
		throw(GradeTooLowException());
	grade += dec;
}

void Bureaucrat::signForm(Form &form)
{
	if (form.getIsSigned())
		std::cout << LIME << getName() << RESET << " couldn't sign " << \
		RED << form.getName() << RESET << " because it is already signed.\n";
	else
	{
		try
		{
			form.beSigned(*this);
			std::cout << LIME << getName() << RESET << " signed " << RED << form.getName() << RESET << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << LIME << getName() << RESET << " couldn't sign " << RED << form.getName() << RESET << " because their grade is too low.\n";
		}
	}
}

std::ostream &operator<<(std::ostream& COUT, Bureaucrat const &bureaucrat)
{
	COUT << LIME << "Bureaucrat with name " << bureaucrat.getName() << " has grade " << bureaucrat.getGrade() << RESET;
	return COUT;
}