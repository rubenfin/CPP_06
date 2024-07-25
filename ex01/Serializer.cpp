/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serializer.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/25 12:24:34 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/07/25 15:41:50 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "This never gets called" << std::endl;
}

Serializer::~Serializer()
{
    std::cout << "And so does this!" << std::endl;
}

uintptr_t Serializer::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data * Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}