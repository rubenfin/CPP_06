/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/03 15:28:46 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/07/24 15:11:25 by rfinneru      ########   odam.nl         */
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
	return (literal.size() == 1 && ((literal.at(0) > 31
				&& literal.at(0) < 127) && !std::isdigit(literal.at(0))));
}

void ScalarConverter::convert(const std::string &literal)
{
	if (checkIfChar(literal))
	{
        std::cout << "char: " << literal << std::endl;
        std::cout << "int: " << static_cast<int>(literal.at(0)) << std::endl;
        std::cout << "float: " << static_cast<float>(literal.at(0)) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(literal.at(0)) << ".0" << std::endl;
    }
	else if (checkIfInt(literal))
	{
        if ((std::stoi(literal) > 31 && std::stoi(literal) < 127))
            std::cout << "char: " << static_cast<char>(std::stoi(literal))<< std::endl;
        else
		    std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << literal << std::endl;
        std::cout << "float: " << static_cast<float>(std::stof(literal)) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(std::stod(literal)) << ".0" << std::endl;
    }
    else if (checkIfFloat(literal))
	{
        if ((std::stoi(literal) > 31 && std::stoi(literal) < 127))
            std::cout << "char: " << static_cast<char>(std::stoi(literal))<< std::endl;
        else
		    std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(std::stoi(literal)) << std::endl;
        std::cout << "float: " << literal << std::endl;
        if (!std::to_string(static_cast<double>(std::stof(literal))).find('.'))
            std::cout << "double: " << static_cast<double>(std::stod(literal)) << std::endl;
        else
            std::cout << "double: " << static_cast<double>(std::stod(literal)) << ".0" << std::endl;
    }
	else if (checkIfDouble(literal))
	{
        if ((std::stoi(literal) > 31 && std::stoi(literal) < 127))
            std::cout << "char: " << static_cast<char>(std::stoi(literal))<< std::endl;
        else
		    std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(std::stoi(literal)) << std::endl;
        if (!std::to_string(static_cast<float>(std::stof(literal))).find('.'))
            std::cout << "float: " << static_cast<float>(std::stof(literal)) << "f" << std::endl;
        else 
            std::cout << "float: " << static_cast<float>(std::stof(literal)) << ".0f" << std::endl;
        std::cout << "double: " << literal << std::endl;
    }
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
}