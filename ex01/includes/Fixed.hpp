/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42helbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:06:05 by bszikora          #+#    #+#             */
/*   Updated: 2025/04/01 20:02:52 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int number;
	static const int bit_number;

public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	Fixed(const int toconvert);
	Fixed(const float toconvert);
	~Fixed();

	int 	getRawBits( void ) const;
	void 	setRawBits( int const raw );
	float 	toFloat( void ) const;
	int 	toInt( void ) const;
};

std::ostream& operator<<(std::ostream& o, const Fixed& fixed);

#endif