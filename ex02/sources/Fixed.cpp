/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42helbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:07:32 by bszikora          #+#    #+#             */
/*   Updated: 2025/05/25 14:13:12 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bit_number = 8;

Fixed::Fixed() : number(0) {std::cout << "Default constructor called\n";}
Fixed::Fixed(const Fixed& other)
{
	this->number = other.number;
	std::cout << "Copy constructor called\n";
}
Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other)
        this->number = other.number;
	return (std::cout << "Copy assignment operator called\n", *this);
}
Fixed::~Fixed() {std::cout << "Destructor called\n";}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return this->number;
}

void	Fixed::setRawBits( int const raw ) {this->number = raw;}

///////////ex01/////////
Fixed::Fixed(const int toconvert)
{
    this->number = toconvert << bit_number;
    std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float toconvert)
{
    this->number = static_cast<int>(roundf(toconvert * (1 << bit_number)));
    std::cout << "Float constructor called\n";
}

std::ostream& operator<<(std::ostream& o, const Fixed& fixed)
{
	o << fixed.toFloat();
	return o;
}

float	Fixed::toFloat( void ) const {return static_cast<float>(this->number) / (1 << bit_number);}
int		Fixed::toInt( void ) const {return this->number >> bit_number;}

///////////ex02/////////

	bool	Fixed::operator>(Fixed const &other) const {return this->number > other.number;}
	bool	Fixed::operator<(Fixed const &other) const {return this->number < other.number;}
	bool	Fixed::operator>=(Fixed const &other) const {return this->number >= other.number;}
	bool	Fixed::operator<=(Fixed const &other) const {return this->number <= other.number;}
	bool	Fixed::operator==(Fixed const &other) const {return this->number == other.number;}
	bool	Fixed::operator!=(Fixed const &other) const {return this->number != other.number;}

	Fixed Fixed::operator+(Fixed const &other) const
	{
		Fixed result;
		result.number = this->number + other.number;
		return result;
	}
	Fixed Fixed::operator-(Fixed const &other) const 
	{
		Fixed result;
		result.number = this->number - other.number;
		return result;
	}
	Fixed Fixed::operator*(Fixed const &other) const
	{
		Fixed result;
		result.number = (this->number * other.number) >> bit_number;
		return result;
	}
	Fixed Fixed::operator/(Fixed const &other) const
	{
		Fixed result;
		result.number = (this->number << bit_number) / other.number;
		return result;
	}

	Fixed& Fixed::operator++()
	{
		this->number += (1 << bit_number);
		return *this;
	}
	Fixed Fixed::operator++(int)
	{
		Fixed temp = *this;
		this->number += (1 << bit_number);
		return temp;
	}
	Fixed& Fixed::operator--()
	{
		this->number -= (1 << bit_number);
		return *this;
	}
	Fixed Fixed::operator--(int)
	{
		Fixed temp = *this;
		this->number -= (1 << bit_number);
		return temp;
	}

		Fixed& Fixed::min(Fixed& compare, Fixed& tocompare) {return (compare < tocompare) ? compare : tocompare;}
		const Fixed& Fixed::min(const Fixed& compare, const Fixed& tocompare) {return (compare < tocompare) ? compare : tocompare;}
		Fixed& Fixed::max(Fixed& compare, Fixed& tocompare) {return (compare > tocompare) ? compare : tocompare;}
		const Fixed& Fixed::max(const Fixed& compare, const Fixed& tocompare) {return (compare > tocompare) ? compare : tocompare;}