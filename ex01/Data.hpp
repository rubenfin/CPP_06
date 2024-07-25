/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Data.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/25 13:30:18 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/07/25 16:42:16 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Serializer.hpp"
#include <string>
#include <array>

class Data
{
private:
    int integer;
    std::string str;

public:
    Data(int i, std::string s);
    ~Data();
    void printDataValues();
};