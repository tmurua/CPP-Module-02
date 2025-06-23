/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:00:20 by tmurua            #+#    #+#             */
/*   Updated: 2025/06/23 11:01:35 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// default constructor: initialize fixed-point value to zero
Fixed::Fixed()
	: rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// copy constructor: copy the rawBits from another Fixed object
Fixed::Fixed(const Fixed &other)
	: rawBits(other.rawBits)
{
	std::cout << "Copy constructor called" << std::endl;
}

// copy assignment operator: assign rawBits from one Fixed to this one
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->rawBits = other.rawBits;
	}
	return *this;
}

// destructor: announce destruction
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// getRawBits: returns the stored fixed-point integer
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return rawBits;
}

// setRawBits: sets the stored fixed-point integer
void Fixed::setRawBits(int const raw)
{
	rawBits = raw;
}
