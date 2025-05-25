/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42helbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:07:32 by bszikora          #+#    #+#             */
/*   Updated: 2025/05/25 15:17:18 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bit_number = 8;

Fixed::Fixed() : number(0) {std::cout << "Default constructor called\n";}
Fixed::Fixed(const Fixed& other) : number(other.number) {std::cout << "Copy constructor called\n";}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		this->number = other.number;
	}
	std::cout << "Copy assignment operator called\n";
	return *this;
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

// int		Fixed::toInt( void ) const {return this->number / (1 << bit_number);}
 int		Fixed::toInt( void ) const {return this->number >> bit_number;}

