/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Data.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/25 13:30:18 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/07/25 16:08:32 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Serializer.hpp"
#include <string>
#include <array>

class Data
{
private:
    static const int integer = 5;
    const std::string str = "Hello World";

public:
    Data();
    ~Data();
    void printDataValues();
};