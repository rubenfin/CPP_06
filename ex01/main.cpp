/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/25 13:32:18 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/07/25 16:39:11 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
    Data *data = new Data;
    Data *deserialized;
    uintptr_t serialized;
    std::cout << BLUE "Starting values:" RESET << std::endl;
    data->printDataValues();
    serialized = Serializer::serialize(data);
    std::cout <<  "\nSerialized pointer: " << YELLOW << serialized << RESET << std::endl;
    deserialized = Serializer::deserialize(serialized);
    if (deserialized == data)
    {
        std::cout << GREEN "\nSUCCES!" RESET << std::endl;
        std::cout << BLUE "\ndeserialized: \n" RESET;
        deserialized->printDataValues();
        std::cout << BLUE "\ndata: \n" RESET;
        data->printDataValues();
    }
    else
        std::cerr << RED "\nDeserializing failed!" RESET << std::endl;
    delete data;
    return (0);
}