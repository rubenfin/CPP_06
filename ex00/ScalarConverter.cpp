/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/03 15:28:46 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/07/25 11:17:09 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool	checkIfDouble(const std::string &literal)
{
	try
	{
		std::stod(literal);
		return (literal.find('.') != std::string::npos);
	}
	catch (std::exception &e)
	{
		return (false);
	}
}

static bool	checkIfFloat(const std::string &literal)
{
	try
	{
		std::stof(literal);
		return (literal.find('f') != std::string::npos
			&& literal.find('.') != std::string::npos);
	}
	catch (std::exception &e)
	{
		return (false);
	}
}

static bool	checkIfInt(const std::string &literal)
{
	if (literal.find('f') != std::string::npos
		|| literal.find('.') != std::string::npos)
		return (false);
	try
	{
		std::stoi(literal);
		return (true);
	}
	catch (std::exception &e)
	{
		return (false);
	}
}

static bool	checkIfChar(const std::string &literal)
{
	return (literal.size() == 1 && ((literal.at(0) > 31 && literal.at(0) < 127)
			&& !std::isdigit(literal.at(0))));
}

static bool	checkIfPseudo(const std::string &literal)
{
	return ((literal == "inf") || (literal == "-inf") || (literal == "+inf")
		|| (literal == "-inff") || (literal == "+inff") || (literal == "nan")
		|| (literal == "nanf"));
}

static void	printPseudo(const std::string &literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (literal == "nanf" || literal == "nan")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "inf" || literal == "+inf" || literal == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

static void	printNoDataType(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
	if (checkIfPseudo(literal))
	{
		printPseudo(literal);
	}
	else if (checkIfChar(literal))
	{
		char c = static_cast<char>(literal.at(0));
		std::cout << "found char" << std::endl;
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	}
	else if (checkIfInt(literal))
	{
		int i = std::stoi(literal);
		std::cout << "found int" << std::endl;
		if ((i > 31 && i < 127))
			std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
	}
	else if (checkIfFloat(literal))
	{
		float f = std::stof(literal);
		std::cout << "found float" << std::endl;
		if ((f > 31 && f < 127))
			std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(f) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
	}
	else if (checkIfDouble(literal))
	{
		std::cout << "found double" << std::endl;
		double d = std::stod(literal);
		if ((d > 31 && d < 127))
			std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(d) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	else
	{
		printNoDataType();
	}
}