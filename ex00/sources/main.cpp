/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42helbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:07:28 by bszikora          #+#    #+#             */
/*   Updated: 2025/06/11 14:03:17 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main()
{
	// Test Default Constructor
	{
		Fixed a;
		std::cout << "Default constructor: " << a.getRawBits() << std::endl;
		Fixed b;
		std::cout << "Default constructor: " << b.getRawBits() << std::endl;
	}

	// Test Copy Constructor
	{
		Fixed a;
		a.setRawBits(123);
		Fixed b(a);
		std::cout << "Copy constructor: " << b.getRawBits() << std::endl;
		a.setRawBits(-456);
		Fixed c(a);
		std::cout << "Copy constructor: " << c.getRawBits() << std::endl;
	}

	// Test Copy Assignment Operator
	{
		Fixed a, b;
		a.setRawBits(789);
		b = a;
		std::cout << "Copy assignment operator: " << b.getRawBits() << std::endl;
		Fixed c;
		c.setRawBits(-321);
		b = c;
		std::cout << "Copy assignment operator: " << b.getRawBits() << std::endl;
	}
	
	return 0;
}