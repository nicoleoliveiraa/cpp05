/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:16:02 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/28 16:34:37 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << "Form default constructor called!" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << "Form constructor with parameters called!" << std::endl;

	if (gradeToSign < 1 || gradeToExec < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec < 1)
        throw GradeTooLowException();
}

Form::Form(const Form& src) : _name(src._name), _isSigned(false), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec)
{
	std::cout << "Form copy constructor called!" << std::endl;
	*this = src;
}

Form& Form::operator=(const Form& src)
{
	std::cout << "Form copy assignment operator called!" << std::endl;
	if (this != &src)
		return (*this);		
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor called!" << std::endl;
} 

std::string Form::getName() const
{
	return (_name);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExec() const
{
	return (_gradeToExec);
}

bool Form::getIsSigned() const
{
	return (_isSigned);
}

void Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
	else
		_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
};

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
};

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "Form " << f.getName() << " requires a grade higher or equal " << f.getGradeToSign();
	os << " to sign, and a grade higher or equal " << f.getGradeToExec() << " to execute, and ";
	if (f.getIsSigned() == true)
		os << "is signed!";
	else
		os << "is not signed!";	
	return (os);
}