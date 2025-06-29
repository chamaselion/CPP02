/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:07:28 by bszikora          #+#    #+#             */
/*   Updated: 2025/06/11 16:46:38 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl << std::endl << std::endl;
	
	Fixed c(10);
	Fixed d(3.5f);
	Fixed e(-2);
	Fixed f(d);
	Fixed g;

	std::cout << "a: " << c << "\n";
	std::cout << "b: " << d << "\n";
	std::cout << "c: " << e << "\n";
	std::cout << "d: " << f << "\n";
	std::cout << "e: " << g << "\n";

	std::cout << std::endl << "a > b: " << (c > d) << "\n";
	std::cout << "a < b: " << (c < d) << "\n";
	std::cout << "a >= b: " << (c >= d) << "\n";
	std::cout << "a <= b: " << (c <= d) << "\n";
	std::cout << "a == b: " << (c == d) << "\n";
	std::cout << "a != b: " << (c != d) << "\n";

	std::cout << "a + b: " << (c + d) << "\n";
	std::cout << "a - b: " << (c - d) << "\n";
	std::cout << "a * b: " << (c * d) << "\n";
	std::cout << "a / b: " << (c / d) << "\n";

	std::cout << "++a: " << ++c << "\n";
	std::cout << "a++: " << c++ << "\n";
	std::cout << "a after a++: " << c << "\n";
	std::cout << "--a: " << --c << "\n";
	std::cout << "a--: " << c-- << "\n";
	std::cout << "a after a--: " << c << "\n";

	std::cout << "min(a, b): " << Fixed::min(c, d) << "\n";
	std::cout << "max(a, b): " << Fixed::max(c, d) << "\n";
	std::cout << "min(c, d): " << Fixed::min(e, f) << "\n";
	std::cout << "max(c, d): " << Fixed::max(e, f) << "\n";

	return 0;
	}
