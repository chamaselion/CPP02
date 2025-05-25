/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42helbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:07:28 by bszikora          #+#    #+#             */
/*   Updated: 2025/04/21 14:08:28 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>
#include "Fixed.hpp"
#include <iostream>

static int tests_failed = 0;

static void assert_equal(float expected, float actual, const char* test_name)
{
    if (std::abs(expected - actual) > 0.0001f) // Allow small floating-point error
    {
        std::cout << "\033[31m" << test_name << " failed: expected "
                  << expected << " got " << actual << "\033[0m\n";
        tests_failed++;
    }
    else
    {
        std::cout << "\033[32m" << test_name << " passed\033[0m\n";
    }
}

int main()
{
    {
        Fixed a;
        assert_equal(0.0f, a.toFloat(), "Default constructor (float)");
        assert_equal(0, a.toInt(), "Default constructor (int)");
    }
    {
        Fixed a(42);
        assert_equal(42.0f, a.toFloat(), "Int constructor (positive)");
        assert_equal(42, a.toInt(), "Int constructor (positive as int)");
    }
    {
        Fixed a(-42);
        assert_equal(-42.0f, a.toFloat(), "Int constructor (negative)");
        assert_equal(-42, a.toInt(), "Int constructor (negative as int)");
    }
    {
        Fixed a(42.42f);
        assert_equal(42.421875f, a.toFloat(), "Float constructor (positive)");
        assert_equal(42, a.toInt(), "Float constructor (positive as int)");
    }
    {
        Fixed a(-42.42f);
        assert_equal(-42.421875f, a.toFloat(), "Float constructor (negative)");
        assert_equal(-42, a.toInt(), "Float constructor (negative as int)");
    }
    {
        Fixed a(0.999f);
        assert_equal(0.99609375f, a.toFloat(), "Float constructor (fraction < 1)");
        assert_equal(0, a.toInt(), "Float constructor (fraction < 1 as int)");
    }
    {
        Fixed a(-0.999f);
        assert_equal(-0.99609375f, a.toFloat(), "Float constructor (negative fraction < 1)");
        assert_equal(0, a.toInt(), "Float constructor (negative fraction < 1 as int)");
    }
    {
        Fixed a(1234.5678f);
        assert_equal(1234.5625f, a.toFloat(), "Float constructor (large positive)");
        assert_equal(1234, a.toInt(), "Float constructor (large positive as int)");
    }
    {
        Fixed a(-1234.5678f);
        assert_equal(-1234.5625f, a.toFloat(), "Float constructor (large negative)");
        assert_equal(-1234, a.toInt(), "Float constructor (large negative as int)");
    }
    {
        Fixed a(2147483647); // INT_MAX
        assert_equal(2147483647.0f, a.toFloat(), "Int constructor (INT_MAX)");
        assert_equal(2147483647, a.toInt(), "Int constructor (INT_MAX as int)");
    }
    {
        Fixed a(static_cast<int>(-2147483648)); // INT_MIN
        assert_equal(-2147483648.0f, a.toFloat(), "Int constructor (INT_MIN)");
        assert_equal(-2147483648, a.toInt(), "Int constructor (INT_MIN as int)");
    }
    {
        Fixed a(0.0f);
        assert_equal(0.0f, a.toFloat(), "Float constructor (zero)");
        assert_equal(0, a.toInt(), "Float constructor (zero as int)");
    }
    {
        Fixed a(1.5f);
        assert_equal(1.5f, a.toFloat(), "Float constructor (fraction .5)");
        assert_equal(1, a.toInt(), "Float constructor (fraction .5 as int)");
    }
    {
        Fixed a(-1.5f);
        assert_equal(-1.5f, a.toFloat(), "Float constructor (negative fraction .5)");
        assert_equal(-1, a.toInt(), "Float constructor (negative fraction .5 as int)");
    }
    {
        Fixed a(0.0001f);
        assert_equal(0.0f, a.toFloat(), "Float constructor (small positive fraction)");
        assert_equal(0, a.toInt(), "Float constructor (small positive fraction as int)");
    }
    {
        Fixed a(-0.0001f);
        assert_equal(0.0f, a.toFloat(), "Float constructor (small negative fraction)");
        assert_equal(0, a.toInt(), "Float constructor (small negative fraction as int)");
    }
    {
        Fixed a(789.123f);
        Fixed b(a);
        assert_equal(789.12109375f, b.toFloat(), "Copy constructor");
        assert_equal(789, b.toInt(), "Copy constructor (as int)");
    }
    {
        Fixed a(42.42f);
        Fixed b;
        b = a;
        assert_equal(42.421875f, b.toFloat(), "Assignment operator");
        assert_equal(42, b.toInt(), "Assignment operator (as int)");
    }
    {
        Fixed a(10.5f), b, c;
        c = b = a;
        assert_equal(10.5f, b.toFloat(), "Chain assignment (b)");
        assert_equal(10.5f, c.toFloat(), "Chain assignment (c)");
    }
    if (tests_failed > 0)
    {
        std::cout << tests_failed << " tests failed\n";
        return 1;
    }
    std::cout << "\033[32mAll tests passed\033[0m\n";
    return 0;
}