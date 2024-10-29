/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:09:42 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/29 20:38:56 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
private:

public:
	Intern();
	Intern(const Intern& src);
	Intern& operator=(const Intern& src);
	~Intern();

	AForm& makePresidentialPardonForm(const std::string target);
	AForm& makeRobotomyRequestForm(std::string target);
	AForm& makeShubberyCreationForm(std::string target);
	
	AForm& makeForm(std::string name, std::string target);

	class FormDoesNotExistException : public std::exception {
	public:
		const char* what() const throw();
	};
};

#endif // INTERN_HPP