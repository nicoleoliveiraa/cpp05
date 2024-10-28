/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:03:50 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/28 16:10:37 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExec;

public:
	Form();
	Form(std::string name, int gradeToSign, int gradeToExec);
	Form(const Form& src);
	Form& operator=(const Form& src);
	~Form();

	std::string getName() const;
	int getGradeToSign() const;
	int getGradeToExec() const;
	bool getIsSigned() const;

	void beSigned(Bureaucrat& b);
	
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& b);

#endif // FORM_HPP