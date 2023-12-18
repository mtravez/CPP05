/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:57:01 by mtravez           #+#    #+#             */
/*   Updated: 2023/10/18 18:10:58 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : isSigned(false), name("default"), signGrade(150), execGrade(150)
{
	return;
}

Form::Form(std::string name, int signGrade, int execGrade) : isSigned(false), name(name), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	if (signGrade < 0 || execGrade < 0)
		throw GradeTooHighException();
	return;
}

Form::Form(Form &form) : isSigned(false), name(form.getName()), signGrade(form.getSignGrade()), execGrade(form.getExecGrade())
{
	return;
}

Form::~Form()
{
	return;
}

Form &Form::operator=(Form &form)
{
	isSigned = form.getIsSigned();
	return *this;
}

const std::string Form::getName() const
{
	return this->name;
}

int Form::getExecGrade() const
{
	return this->execGrade;
}

bool Form::getIsSigned() const
{
	return this->isSigned;
}

int Form::getSignGrade() const
{
	return this->signGrade;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	else
		this->isSigned = true;
}

std::ostream &operator<<(std::ostream& COUT, Form const &form)
{
	COUT << RED << "Form with name " << form.getName();
	if (form.getIsSigned())
		COUT << " is signed";
	else
		COUT << " is not signed";
	COUT << ". Grade to sign: " << form.getSignGrade() << " Grade to execute: " << form.getExecGrade() << RESET;
	return COUT;
}