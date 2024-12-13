/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/03 15:28:32 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/12/12 15:30:48 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iomanip>
#include <iostream>
#include <limits.h>
#include <limits>
#include <string>

class ScalarConverter
{
private:
	ScalarConverter();
public:
	static void convert(const std::string &literal);
};
