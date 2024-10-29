/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:27:39 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/29 19:20:14 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << "ShrubberyCreationForm default constructor called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor with target parameter called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm copy constructor called!" << std::endl;
	*this = src;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	std::cout << "ShrubberyCreationForm copy assignment operator called!" << std::endl;
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called!" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	AForm::canExecute(executor);

	std::ofstream outFile;
	std::string fileName = executor.getName() + "_shrubbery";
	
	outFile.open(fileName.c_str(), std::ios::out | std::ios::trunc);
	if (!outFile.good())
	{
		std::cerr << "Error: Can't open outFile." << std::endl;
		return ;
	}

	outFile << "               @@@ @@  @ @@               \n";
    outFile << "           @@ @@@/@@@|@ ()|/ @, @@         \n";
    outFile << "           @@@/(/@/@||/@ /_/)_@/_@        \n";
    outFile << "        @() @@@/@|()|/@@@/ @@@@ @ ()     \n";
    outFile << "       @_@@_@@_@@ |@ |@@/@__@@_/_@ @@   \n";
    outFile << "  @@   @@ @ @| @| /@ @ @@ ()@ /@@         \n";
    outFile << "      ()@_---()@@@@@@|@@-@@--@@---()~  \n";
    outFile << "               @@    |||               \n";
    outFile << "                     |||               \n";
    outFile << "                     |||               \n";
    outFile << "                     |||               \n";
    outFile << "                     |||               \n";
    outFile << "                 ||||||||||||           \n";
	
	outFile.close();
}