/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serializer.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/25 12:24:26 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/07/25 16:31:42 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Colors.hpp"
#include "Data.hpp"
#include <cstdint>
#include <iostream>

class Data;

class Serializer
{
private:
    Serializer();
    ~Serializer();
public:
    Serializer(const Serializer &other) = delete;
    Serializer &operator=(const Serializer& other) = delete;
    static uintptr_t serialize(Data *ptr);
    static Data * deserialize(uintptr_t raw);
};
