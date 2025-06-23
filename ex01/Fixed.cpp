/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 14:54:19 by tmurua            #+#    #+#             */
/*   Updated: 2025/06/23 15:06:56 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// default constructor: rawBits starts at 0
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

// float constructor: multiply by 2^fractionalBits and round to nearest
Fixed::Fixed(float const floatValue)
	: rawBits(static_cast<int>(roundf(floatValue * (1 << fractionalBits))))
{
	std::cout << "Float constructor called" << std::endl;
}

// copy constructor: copy rawBits directly
Fixed::Fixed(Fixed const &other)
	: rawBits(other.rawBits)
{
	std::cout << "Copy constructor called" << std::endl;
}

// copy assignment: guard against self-assignment and copy rawBits
Fixed &Fixed::operator=(Fixed const &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->rawBits = other.rawBits;
	return *this;
}

// destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// returns raw fixed-point data
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return rawBits;
}

// sets raw fixed-point data
void Fixed::setRawBits(int const raw)
{
	rawBits = raw;
}

// convert fixed-point to float by dividing by 2^fractionalBits
float Fixed::toFloat(void) const
{
	return static_cast<float>(rawBits) / (1 << fractionalBits);
}

// convert fixed-point to int by shifting right
int Fixed::toInt(void) const
{
	return rawBits >> fractionalBits;
}

// overload << to print float representation to output stream
std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
	out << value.toFloat();
	return out;
}
