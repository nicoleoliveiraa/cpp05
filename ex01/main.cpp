/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:18:26 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/28 16:44:30 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define RESET   "\033[0m"
#define BOLD_YELLOW  "\033[1m\033[33m"
#define BOLD_BLUE    "\033[1m\033[34m"
#define BOLD_CYAN    "\033[1m\033[36m"

int main()
{
	{
		std::cout << BOLD_CYAN << "Constructing" << RESET << std::endl;
		Bureaucrat* a = new Bureaucrat();
		Bureaucrat* aa = new Bureaucrat("Assistant", 130);
		Bureaucrat* bb = new Bureaucrat("Assistant", 1);
		Bureaucrat* c = new Bureaucrat("Intern", 149);
		std::cout << std::endl;
		Form* f = new Form();
		Form* ff = new Form("Rent Contract", 20, 20);
		Form* newf = new Form("Contract", 140, 20);
		
		std::cout << *a << std::endl;
		std::cout << *aa << std::endl;
		std::cout << *bb << std::endl;
		std::cout << *f << std::endl;
		std::cout << *ff << std::endl;

		std::cout << std::endl;
		std::cout << BOLD_YELLOW << "Testing" << RESET << std::endl;
		
		a->signForm(*f);
		a->signForm(*ff);
		std::cout << std::endl;

		aa->signForm(*f);
		aa->signForm(*ff);
		std::cout << std::endl;

		bb->signForm(*f);
		bb->signForm(*ff);
		std::cout << std::endl;
		
		try
		{
			newf->beSigned(*c);
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cout << c->getName() << " can't sign " << newf->getName() << ":" << std::endl;
			std::cout << e.what() << std::endl;
		}
		
		std::cout << std::endl;
		std::cout << BOLD_BLUE << "Deconstructing" << RESET << std::endl;
		
		delete a;
		delete aa;
		delete f;
		delete ff;
		delete bb;
		delete c;
	}
}