/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/26 11:41:34 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/12/13 10:57:50 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

void	identify(Base *p)
{
	A	*a;
	B	*b;
	C	*c;

	a = dynamic_cast<A *>(p);
	b = dynamic_cast<B *>(p);
	c = dynamic_cast<C *>(p);
	if (a)
		std::cout << YELLOW "Class is A" RESET << std::endl;
	else if (b)
		std::cout << YELLOW "Class is B" RESET << std::endl;
	else if (c)
		std::cout << YELLOW "Class is C" RESET << std::endl;
	else
		std::cerr << RED "Class not Found" RESET << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << BLUE "Class is A" RESET << std::endl;
		return;
	}
	catch (const std::bad_cast&) {}
	
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << BLUE "Class is B" RESET << std::endl;
		return;
	}
	catch (const std::bad_cast&) {}
	
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << BLUE "Class is C" RESET << std::endl;
		return;
	}
	catch (const std::bad_cast&) {}
	
	std::cerr << RED "Class not Found" RESET << std::endl;
}

Base	*generate(void)
{
	int		random;
	Base	*rdm;

	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<> dist(0, 2);
	random = dist(rng);
	if (!random)
		rdm = new A;
	else if (random == 1)
		rdm = new B;
	else
		rdm = new C;
	return (rdm);
}

int	main(void)
{
	Base *randomClass;
	randomClass = generate();
	identify(randomClass);
	identify(*randomClass);
	delete randomClass;
	return (0);
}