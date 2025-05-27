/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:07:28 by bszikora          #+#    #+#             */
/*   Updated: 2025/05/27 13:19:24 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static int tests_failed = 0;

static void assert_equal(int expected, int actual, const char* test_name)
{
    if (expected != actual)
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
        assert_equal(0, a.getRawBits(), "Default constructor");
    }
    {
        Fixed a;
        a.setRawBits(123);
        assert_equal(123, a.getRawBits(), "set/get positive raw bits");
        a.setRawBits(-456);
        assert_equal(-456, a.getRawBits(), "set/get negative raw bits");
    }
    {
        Fixed a;
        a.setRawBits(2147483647);
        assert_equal(2147483647, a.getRawBits(), "set/get INT_MAX");
        a.setRawBits(-2147483648);
        assert_equal(-2147483648, a.getRawBits(), "set/get INT_MIN");
    }
    {
        Fixed a;
        a.setRawBits(3.7f);
        assert_equal(3, a.getRawBits(), "setRawBits positive float literal");
        a.setRawBits(-3.7);
        assert_equal(-3, a.getRawBits(), "setRawBits negative double literal");
    }
    {
        Fixed a;
        a.setRawBits(0.999f);
        assert_equal(0, a.getRawBits(), "setRawBits positive fraction <1");
        a.setRawBits(-0.999);
        assert_equal(0, a.getRawBits(), "setRawBits negative fraction >-1");
    }
    {
        Fixed a;
        a.setRawBits(1.5f);
        assert_equal(1, a.getRawBits(), "setRawBits positive fraction .5");
        a.setRawBits(-1.5);
        assert_equal(-1, a.getRawBits(), "setRawBits negative fraction .5");
    }
    {
        Fixed a;
        a.setRawBits(789);
        Fixed b(a);
        assert_equal(789, b.getRawBits(), "copy constructor");
    }
    {
        Fixed a;
        a.setRawBits(42);
        Fixed b;
        b = a;
        assert_equal(42, b.getRawBits(), "assignment operator");
        b = b;
        assert_equal(42, b.getRawBits(), "self assignment");
    }
    {
        Fixed a, b, c;
        a.setRawBits(10);
        c = b = a;
        assert_equal(10, b.getRawBits(), "chain assignment b");
        assert_equal(10, c.getRawBits(), "chain assignment c");
    }
    if (tests_failed > 0)
    {
        std::cout << tests_failed << " tests failed\n";
        return 1;
    }
    std::cout << "\033[32mAll tests passed\033[0m\n";
    return 0;
}