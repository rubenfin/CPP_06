/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/03 15:28:32 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/07/25 11:56:15 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <limits.h>
#include <limits>

class ScalarConverter
{
  private:
	ScalarConverter();
  public:
	static void convert(const std::string &literal);
};
