/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:18:26 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/28 16:45:52 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define RESET   "\033[0m"
#define BOLD_YELLOW  "\033[1m\033[33m"
#define BOLD_BLUE    "\033[1m\033[34m"
#define BOLD_CYAN    "\033[1m\033[36m"
#define BOLD_RED     "\033[1m\033[31m"

int main()
{
	{
		std::cout << BOLD_CYAN << "Constructing" << RESET << std::endl;
		Bureaucrat *a = new Bureaucrat();
		std::cout << std::endl;

		std::cout << BOLD_YELLOW << "Testing" << RESET << std::endl;
		std::cout << *a << std::endl;

		try
		{
		a->incrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << BOLD_RED << "Incrementing grade of " << a->getName() <<
			" failed: " << e.what() << RESET << std::endl;
		}

		std::cout << *a << std::endl;

		try
		{
		a->decrementGrade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << BOLD_RED << "Decrementing grade of " << a->getName() <<
			" failed: " << e.what() << RESET << std::endl;
		}

		std::cout << *a << std::endl;

		try
		{
		a->decrementGrade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << BOLD_RED "Decrementing grade of " << a->getName() <<
			" failed: " << e.what() << RESET << std::endl;
		}

		std::cout << *a << std::endl;
		std::cout << std::endl;

		std::cout << BOLD_BLUE << "Deconstructing" << RESET << std::endl;
		delete a;
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;
		std::cout << BOLD_CYAN << "Constructing" << RESET << std::endl;
		Bureaucrat *a = NULL;
		try
		{
			a = new Bureaucrat("Batman", 0);
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << BOLD_RED << "Construction failed: " << e.what() << RESET << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << BOLD_RED << "Construction failed: " << e.what() << RESET << std::endl;
		}
		if (a)
		{
			std::cout << *a << std::endl;
			delete a;
		}
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;
		std::cout << BOLD_CYAN << "Constructing" << RESET << std::endl;
		Bureaucrat *a = new Bureaucrat("Peter", 120);
		std::cout << std::endl;

		std::cout << BOLD_YELLOW << "Testing a" << RESET << std::endl;
		std::cout << *a << std::endl;

		try
		{
		a->incrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << BOLD_RED << "Incrementing grade of " << a->getName() <<
			" failed: " << e.what() << RESET << std::endl;
		}

		std::cout << *a << std::endl;
		a->decrementGrade();

		std::cout << *a << std::endl;
		std::cout << std::endl;

		std::cout << BOLD_CYAN << "Constructing b" << RESET << std::endl;
		Bureaucrat *b = new Bureaucrat(*a);
		std::cout << std::endl;

		std::cout << BOLD_BLUE << "Deconstructing a" << RESET << std::endl;
		delete a;
		std::cout << std::endl;

		std::cout << BOLD_YELLOW << "Testing b" << RESET << std::endl;
		std::cout << *b << std::endl;
		b->decrementGrade();
		std::cout << *b << std::endl;
		std::cout << std::endl;

		std::cout << BOLD_BLUE << "Deconstructing b" << RESET << std::endl;
		delete b;

		std::cout << std::endl;
	}
}