/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/03 15:28:32 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/07/24 12:15:10 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ScalarConverter
{
  private:
	ScalarConverter();
  public:
	static void convert(const std::string &literal);
};
