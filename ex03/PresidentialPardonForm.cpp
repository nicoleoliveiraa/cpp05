/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:47:01 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/30 14:32:44 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#define BOLD_GREEN       "\033[1m\033[32m"
#define RESET   "\033[0m"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default")
{
	std::cout << "PresidentialPardonForm default constructor called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm constructor with target parameter called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm copy constructor called!" << std::endl;
	*this = src;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	std::cout << "PresidentialPardonForm copy assignment operator called!" << std::endl;
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called!" << std::endl;
}


void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{	
	AForm::canExecute(executor);

	std::cout << BOLD_GREEN << _target << " has been pardoned by Zaphod Beeblebrox!" << RESET << std::endl;
}