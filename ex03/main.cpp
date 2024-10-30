/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:18:26 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/30 15:08:20 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#define RESET   "\033[0m"
#define RED         "\033[31m"
#define BOLD_MAGENTA     "\033[1m\033[35m"
#define BOLD_RED         "\033[1m\033[31m"
#define BOLD_CYAN    "\033[1m\033[36m"
#define BOLD_YELLOW  "\033[1m\033[33m"
#define BOLD_BLUE    "\033[1m\033[34m"

int main()
{
	Intern dum;
	
	std::cout << std::endl;
	std::cout << BOLD_YELLOW << "-------> Non-existent Form Test <-------" << RESET << std::endl;
	std::cout << std::endl;

	{
		Bureaucrat bu("Max Weber", 15);
		AForm* form = NULL; 
	
		try
		{
			form = &dum.makeForm("nonexistent", "Mr. X");
		}
		catch(const std::exception& e)
		{
			std::cerr << BOLD_RED << e.what() << RESET << std::endl;
		}
		if (form)
		{
			bu.signForm(*form);
			bu.executeForm(*form);
		}
	
		delete form;
	}
	
	std::cout << std::endl;
	std::cout << BOLD_YELLOW << "-------> ShrubberyCreationForm Test <-------" << RESET << std::endl;
	std::cout << std::endl;

	{
		Bureaucrat bOne("Max Weber", 15);
		AForm* sForm = NULL; 

		try
		{
			sForm = &dum.makeForm("ShrubberyCreationForm", "Mr. X");
		}
		catch(const std::exception& e)
		{
			std::cerr << BOLD_RED << e.what() << RESET << std::endl;
		}
		
		bOne.signForm(*sForm);
		bOne.executeForm(*sForm);

		delete sForm;

	}
	
	std::cout << std::endl;
	std::cout << BOLD_YELLOW << "-------> RobotomyRequestForm Test <-------" << RESET << std::endl;
	std::cout << std::endl;

	{
		Bureaucrat bTwo("Max Weber", 30);
		AForm* rForm = NULL; 

		try
		{
			rForm = &dum.makeForm("RobotomyRequestForm", "Mr. X");
		}
		catch(const std::exception& e)
		{
			std::cerr << BOLD_RED << e.what() << RESET << std::endl;
		}
	
		bTwo.signForm(*rForm);
		bTwo.executeForm(*rForm);
	
		delete rForm;
	
	}

	std::cout << std::endl;
	std::cout << BOLD_YELLOW << "-------> PresidentialPardonForm Test <-------" << RESET << std::endl;
	std::cout << std::endl;

	{
		Bureaucrat bThree("Max Weber", 1);
		AForm* pForm = NULL; 

		try
		{
			pForm = &dum.makeForm("PresidentialPardonForm", "Mr. X");
		}
		catch(const std::exception& e)
		{
			std::cerr << BOLD_RED << e.what() << RESET << std::endl;
		}
	
		bThree.signForm(*pForm);
		bThree.executeForm(*pForm);
	
		delete pForm;
	
	}
	
}