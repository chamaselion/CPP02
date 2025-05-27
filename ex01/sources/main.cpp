/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:07:28 by bszikora          #+#    #+#             */
/*   Updated: 2025/05/27 13:19:00 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// static int tests_failed = 0;

// static void	assert_equal(float expected, float actual, const char* test_name)
// {
//     float	epsilon;

//     epsilon = 0.0001f;
//     if (std::abs(expected) > 100.0f)
//     {
//         epsilon = 0.05f;
//     }
//     if (std::abs(expected - actual) > epsilon)
//     {
//         std::cout << "\033[31m" << test_name << " failed: expected "
//             << expected << " got " << actual << "\033[0m\n";
//         tests_failed++;
//     }
//     else
//     {
//         std::cout << "\033[32m" << test_name << " passed\033[0m\n";
//     }
// }


int main(void)
{
	Fixed a;
	Fixed const b(10.10f);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}