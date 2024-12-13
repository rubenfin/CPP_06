/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/03 15:28:46 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/12/12 15:36:55 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool endsWithZeroPointZero(int number) {
    std::string strNumber = std::to_string(number);
	
	if (strNumber.length() - 2 == std::string::npos)
		return (false);
	
    return strNumber.find(".0") == strNumber.length() - 2;
}

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

static void printDouble(const std::string &literal)
{
	double d = std::stod(literal);
	long long l = std::stoll(literal);

	if ((d > 31 && d < 127))
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (std::stoll(literal) > INT_MAX || std::stoll(literal) < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	if (l > std::numeric_limits<float>::max()
	|| l < std::numeric_limits<float>::min() )
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<double>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

static void	printFloat(const std::string &literal)
{
	float	f;
	long long l = std::stoll(literal);

	f = std::stof(literal);
	if ((f > 31 && f < 127))
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (l > INT_MAX || l < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: "  << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

static void	printInt(const std::string &literal)
{
	int	i;
	i = std::stoi(literal);
	if ((i > 31 && i < 127))
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	if (endsWithZeroPointZero(static_cast<double>(i)))
		std::cout << "float: " << static_cast<double>(i) << 'f' << std::endl;
	else
		std::cout << "float: " << static_cast<double>(i) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

static void printChar(const std::string &literal)
{
	char c = static_cast<char>(literal.at(0));
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

static void	printNoDataType(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

static int countPrecision(const std::string &literal)
{
    std::size_t dot = literal.find('.');

    if (dot == std::string::npos)
        return 1;

    std::size_t precisionCount = 0;
    for (std::size_t i = dot + 1; i < literal.size(); ++i)
    {
        if (std::isdigit(literal[i]))
            ++precisionCount;
        else
            break;
    }
    return precisionCount;
}

void ScalarConverter::convert(const std::string &literal)
{
	std::cout << std::fixed << std::setprecision(countPrecision(literal)) << std::endl;
	try
	{
	if (checkIfPseudo(literal))
		printPseudo(literal);
	else if (checkIfChar(literal))
		printChar(literal);
	else if (checkIfInt(literal))
		printInt(literal);
	else if (checkIfFloat(literal))
		printFloat(literal);
	else if (checkIfDouble(literal))
		printDouble(literal);
	else
		printNoDataType();
	}
	catch(const std::exception &e)
	{
		printNoDataType();
	}
}