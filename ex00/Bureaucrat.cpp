/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:15:50 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/25 16:41:40 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(0)
{
	std::cout << "Default constructor called!" << std::endl;
}

Bureaucrat::Bureaucrat(std::cout name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Constructor with parameters called!" << std::endl;

	if (grade < 1)
        throw std::string("Grade is too high!");
    if (grade > 150)
        throw std::string("Grade is too low!");
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
{
	std::cout << "Copy constructor called!" << std::endl;
	*this = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	std::cout << "Copy assignment operator called!" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_grade = src._grade;		
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called!" << std::endl;
}

std::string Bureaucrat::getName()
{
	return (this->_name);
}

int Bureaucrat::getGrade()
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	if (grade - 1 < 1)
        throw std::string("Grade is too high!");
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade + 1 > 150)
        throw std::string("Grade is too low!");
	this->_grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}

class GradeTooHighException : public std::exception
{
	
}