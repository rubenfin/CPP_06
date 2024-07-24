/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/03 15:51:23 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/07/24 12:14:21 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
        ScalarConverter::convert(av[1]);
    else
        std::cerr << "ScalarConverter::convert can only take one argument" << std::endl;
    return 0;
}