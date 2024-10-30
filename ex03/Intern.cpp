/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:10:52 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/30 11:10:36 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called!" << std::endl;
}

Intern::Intern(const Intern& src)
{
	std::cout << "Intern copy constructor called!" << std::endl;
	*this = src;
}

Intern& Intern::operator=(const Intern& src)
{
	std::cout << "Intern copy assignment operator called!" << std::endl;
	if (this != &src)
		return (*this);		
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called!" << std::endl;
}

AForm* Intern::makePresidentialPardonForm(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeRobotomyRequestForm(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makeShubberyCreationForm(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm& Intern::makeForm(std::string name, std::string target)
{
	std::string forms[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	AForm* (Intern::*formCreators[])(const std::string) = {&Intern::makePresidentialPardonForm, &Intern::makeRobotomyRequestForm, &Intern::makeShubberyCreationForm};

	for (int i = 0; i < 3; ++i)
	{
		if (!name.compare(forms[i]))
			return *(this->*formCreators[i])(target);
	}
	
	throw FormDoesNotExistException();
}

const char *Intern::FormDoesNotExistException::what(void) const throw()
{
	return "Coudn't create a form: Nonexistent form type!";
};
