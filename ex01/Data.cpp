/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Data.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/25 16:05:58 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/07/25 16:38:45 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data()
{
    
}

Data::~Data()
{
    
}

void Data::printDataValues()
{
    std::cout << "Pointer to data struct: " CYAN << this << RESET << std::endl;
    std::cout << "Integer: " << this->integer << std::endl;
    std::cout << "String: " << this->str << std::endl;
}