/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:47:01 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/30 15:01:43 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#define BOLD_WHITE       "\033[1m\033[37m"
#define BOLD_BLUE    "\033[1m\033[34m"
#define RESET   "\033[0m"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << "RobotomyRequestForm default constructor called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor with target parameter called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm copy constructor called!" << std::endl;
	*this = src;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	std::cout << "RobotomyRequestForm copy assignment operator called!" << std::endl;
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called!" << std::endl;
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	int isFailed = 0;
	
	srand((unsigned) time(NULL));
	isFailed = rand();
	
	AForm::canExecute(executor);

	std::cout << BOLD_WHITE << "*Brrrrrrrrr...*\n*Vrrrrooooom...*\n*Drrrrrrrrrrr...*\n";
	std::cout << "*Tap, tap, tap...*\n*Chhhhhh...*\n*Whirr, whirr, whirr...*" << RESET << std::endl;
	
	if (isFailed % 2)
		std::cout << BOLD_BLUE << _target << " was robotomized!" << RESET << std::endl;
	else
		std::cout << BOLD_BLUE << "The robotomy of " << _target << " failed!" << RESET << std::endl;
}