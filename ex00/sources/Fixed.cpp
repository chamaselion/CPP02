/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42helbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:07:32 by bszikora          #+#    #+#             */
/*   Updated: 2025/05/25 13:55:33 by bszikora         ###   ########.fr       */
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

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return this->number;
}

void Fixed::setRawBits( int const raw ) {this->number = raw;}