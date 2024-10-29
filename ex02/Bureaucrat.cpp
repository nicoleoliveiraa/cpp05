/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:15:50 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/29 19:56:58 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define BOLD_RED         "\033[1m\033[31m"
#define BOLD_CYAN    "\033[1m\033[36m"
#define BOLD_MAGENTA     "\033[1m\033[35m"
#define RED         "\033[31m"
#define RESET   "\033[0m"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called!" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat constructor with parameters called!" << std::endl;

	if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name)
{
	std::cout << "Bureaucrat copy constructor called!" << std::endl;
	*this = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	std::cout << "Bureaucrat copy assignment operator called!" << std::endl;
	if (this != &src)
		this->_grade = src._grade;		
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called!" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
         throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
        throw GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signForm(AForm& form)
{
	if (form.getIsSigned() == true)
	{
		std::cout << BOLD_CYAN << "Form " << form.getName() << " already signed!" << RESET << std::endl;
		return ;
	}
	try
	{
		form.beSigned(*this);
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << BOLD_RED << _name << " couldn’t sign " << form.getName() << RESET;
        std::cout << RED << " because their grade (" << _grade;
        std::cout << ") is too low. Required grade: " << form.getGradeToSign() << "." << RESET << std::endl;
		return ;
	}
	std::cout << BOLD_CYAN << _name << " sign " << form.getName() << "!" << RESET << std::endl;
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD_RED << "Bureaucrat " << _name << " couldn’t execute " << form.getName() << ": " << RESET;
		std::cerr << RED << e.what() << RESET << std::endl;
		return ;
	}
	std::cout << BOLD_MAGENTA << _name << " executed " << form.getName() << "!" << RESET << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
};

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (os);
}