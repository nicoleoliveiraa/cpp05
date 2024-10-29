/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:03:50 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/29 18:54:23 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm {
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExec;

public:
	AForm();
	AForm(std::string name, int gradeToSign, int gradeToExec);
	AForm(const AForm& src);
	AForm& operator=(const AForm& src);
	virtual ~AForm();

	std::string getName() const;
	int getGradeToSign() const;
	int getGradeToExec() const;
	bool getIsSigned() const;

	void beSigned(Bureaucrat& b);
	
	void canExecute(Bureaucrat const & executor) const;
	virtual void execute(Bureaucrat const & executor) const = 0;
	
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};

	class FormNotSignedException : public std::exception {
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& b);

#endif // AFORM_HPP