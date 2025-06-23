/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:25:42 by tmurua            #+#    #+#             */
/*   Updated: 2025/06/23 15:31:47 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

// Fixed: a fixed-point number with 8 fractional bits in Orthodox Canonical Form
class Fixed
{
private:
	int					rawBits;			// underlying integer representation
	static const int	fractionalBits = 8;	// number of bits for fractional part

public:
	// constructors & destructor
	Fixed();								// default: 0.0
	Fixed(int const intValue);				// from integer
	Fixed(float const floatValue);			// from float
	Fixed(Fixed const &other);				// copy
	Fixed &operator=(Fixed const &other);	// assign
	~Fixed();								// destructor

	// raw accessors
	int  getRawBits(void) const;			// get raw integer
	void setRawBits(int const raw);			// set raw integer

	// converters
	float toFloat(void) const;				// to float
	int   toInt(void) const;				// to int

	// comparison operators
	bool operator>(Fixed const &other) const;
	bool operator<(Fixed const &other) const;
	bool operator>=(Fixed const &other) const;
	bool operator<=(Fixed const &other) const;
	bool operator==(Fixed const &other) const;
	bool operator!=(Fixed const &other) const;

	// arithmetic operators
	Fixed operator+(Fixed const &other) const;
	Fixed operator-(Fixed const &other) const;
	Fixed operator*(Fixed const &other) const;
	Fixed operator/(Fixed const &other) const;

	// increment / decrement
	Fixed &operator++();	// pre-increment: increments by smallest step
	Fixed  operator++(int);	// post-increment
	Fixed &operator--();	// pre-decrement
	Fixed  operator--(int);	// post-decrement

	// min/max static functions
	static Fixed       &min(Fixed &a, Fixed &b);
	static Fixed const &min(Fixed const &a, Fixed const &b);
	static Fixed       &max(Fixed &a, Fixed &b);
	static Fixed const &max(Fixed const &a, Fixed const &b);
};

// stream insertion: output the floating-point representation
std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif
