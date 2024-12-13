/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Data.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/25 13:30:18 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/11/02 12:33:42 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Serializer.hpp"
#include <string>
#include <array>

class Data
{
private:
    int _value;
    std::string _name;

public:
    Data(int value, std::string name);
    ~Data();
    void printDataValues();
};