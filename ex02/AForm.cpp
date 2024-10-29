/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:16:02 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/29 18:54:15 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << "AForm default constructor called!" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << "AForm constructor with parameters called!" << std::endl;

	if (gradeToSign < 1 || gradeToExec < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec < 1)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& src) : _name(src._name), _isSigned(false), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec)
{
	std::cout << "AForm copy constructor called!" << std::endl;
	*this = src;
}

AForm& AForm::operator=(const AForm& src)
{
	std::cout << "AForm copy assignment operator called!" << std::endl;
	if (this != &src)
		return (*this);		
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm destructor called!" << std::endl;
} 

std::string AForm::getName() const
{
	return (_name);
}

int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExec() const
{
	return (_gradeToExec);
}

bool AForm::getIsSigned() const
{
	return (_isSigned);
}

void AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
	else
		_isSigned = true;
}

void AForm::canExecute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > _gradeToExec)
		throw AForm::GradeTooLowException();
	if (_isSigned == false)
		throw AForm::FormNotSignedException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
};

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
};

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return "Form needs to be signed before executing!";
};

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "AForm " << f.getName() << " requires a grade higher or equal " << f.getGradeToSign();
	os << " to sign, and a grade higher or equal " << f.getGradeToExec() << " to execute, and ";
	if (f.getIsSigned() == true)
		os << "is signed!";
	else
		os << "is not signed!";	
	return (os);
}