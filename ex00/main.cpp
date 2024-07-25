/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/03 15:51:23 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/07/25 12:17:14 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <vector>
// int main(int ac, char **av)
// {
//     if (ac == 2)
//         ScalarConverter::convert(av[1]);
//     else
//         std::cerr << "usage: ./Scalar [\"argument\"]" << std::endl;
//     return 0;
// }

int main() {
    std::vector<std::string> testCases = {
        "0",
        "1",
        "-1",
        "3.1415927f",
        "-3.1415927f",
        "1.0e-38f",
        "-1.0e-38f",
        "nanf",
        "-inff",
        "+inff",
        "42",
        "42.0",
        "42.0f",
        "2147483647", // Maximum 32-bit int
        "-2147483648", // Minimum 32-bit int
        std::to_string(std::numeric_limits<float>::max()),
        std::to_string(std::numeric_limits<float>::min())
    };

    for (const auto& testCase : testCases) {
        std::cout << "\ninput: " << testCase << "\n" << std::endl;
        ScalarConverter::convert(testCase);
    }

    return 0;
}