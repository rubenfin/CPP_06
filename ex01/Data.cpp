/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Data.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/25 16:05:58 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/11/02 12:27:01 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(int value, std::string name) : _value(value), _name(name)
{
}

Data::~Data()
{
}

void Data::printDataValues()
{
    std::cout << "Pointer to data struct: " CYAN << this << RESET << std::endl;
    std::cout << "Integer: " << this->_value << std::endl;
    std::cout << "String: " << this->_name << std::endl;
}