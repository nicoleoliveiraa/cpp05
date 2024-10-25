/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:02:04 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/25 17:01:55 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
protected:
	const std::string _name;
	int	_grade;
	
public:
	Bureaucrat();
	Bureaucrat(int grade);
	Bureaucrat(const Bureaucrat& src);
	Bureaucrat& operator=(const Bureaucrat& src);
	~Bureaucrat();

	std::string getName();
	int getGrade();

	void incrementGrade();
	void decrementGrade();

	//class GradeTooHighException : public std::exception;
	//class GradeTooLowException : public std::exception;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif // BUREAUCRAT_HPP