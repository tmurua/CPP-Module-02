/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:25:41 by tmurua            #+#    #+#             */
/*   Updated: 2025/06/23 15:34:57 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// default constructor: initializes to 0.0
Fixed::Fixed()
	: rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// integer constructor: shift left to store integer part
Fixed::Fixed(int const intValue)
	: rawBits(intValue << fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

// float constructor: multiply, round, and store
Fixed::Fixed(float const floatValue)
	: rawBits(static_cast<int>(roundf(floatValue * (1 << fractionalBits))))
{
	std::cout << "Float constructor called" << std::endl;
}

// copy constructor: copy rawBits
Fixed::Fixed(Fixed const &other)
	: rawBits(other.rawBits)
{
	std::cout << "Copy constructor called" << std::endl;
}

// copy assignment: copy rawBits, guard self-assignment
Fixed &Fixed::operator=(Fixed const &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->rawBits = other.rawBits;
	return *this;
}

// destructor: announce destruction
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// get raw integer value
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return rawBits;
}

// set raw integer value
void Fixed::setRawBits(int const raw)
{
	rawBits = raw;
}

// convert to float by dividing by 2^fractionalBits
float Fixed::toFloat(void) const
{
	return static_cast<float>(rawBits) / (1 << fractionalBits);
}

// convert to int by shifting right
int Fixed::toInt(void) const
{
	return rawBits >> fractionalBits;
}

// comparison operators compare rawBits directly
bool Fixed::operator>(Fixed const &other) const { return rawBits > other.rawBits; }
bool Fixed::operator<(Fixed const &other) const { return rawBits < other.rawBits; }
bool Fixed::operator>=(Fixed const &other) const { return rawBits >= other.rawBits; }
bool Fixed::operator<=(Fixed const &other) const { return rawBits <= other.rawBits; }
bool Fixed::operator==(Fixed const &other) const { return rawBits == other.rawBits; }
bool Fixed::operator!=(Fixed const &other) const { return rawBits != other.rawBits; }

// arithmetic operators perform operations on rawBits and adjust scaling
Fixed Fixed::operator+(Fixed const &other) const
{
	Fixed result;
	result.rawBits = this->rawBits + other.rawBits;
	return result;
}

Fixed Fixed::operator-(Fixed const &other) const
{
	Fixed result;
	result.rawBits = this->rawBits - other.rawBits;
	return result;
}

Fixed Fixed::operator*(Fixed const &other) const
{
	Fixed result;
	// multiply raw values then shift down by fractionalBits to maintain scale
	long temp = static_cast<long>(rawBits) * other.rawBits;
	result.rawBits = static_cast<int>(temp >> fractionalBits);
	return result;
}

Fixed Fixed::operator/(Fixed const &other) const
{
	Fixed result;
	// shift up before division to maintain precision
	long temp = (static_cast<long>(rawBits) << fractionalBits) / other.rawBits;
	result.rawBits = static_cast<int>(temp);
	return result;
}

// pre-increment: increment smallest amount (1 raw unit)
Fixed &Fixed::operator++()
{
	++rawBits;
	return *this;
}

// post-increment: return old value, then increment
Fixed Fixed::operator++(int)
{
	Fixed old(*this);
	++rawBits;
	return old;
}

// pre-decrement
Fixed &Fixed::operator--()
{
	--rawBits;
	return *this;
}

// post-decrement
Fixed Fixed::operator--(int)
{
	Fixed old(*this);
	--rawBits;
	return old;
}

// static min/max return the smaller/larger reference
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a > b ? a : b);
}

// stream insertion prints the floating-point value
std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
	out << value.toFloat();
	return out;
}
