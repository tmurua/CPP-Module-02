/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 14:48:20 by tmurua            #+#    #+#             */
/*   Updated: 2025/06/23 15:05:27 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

// the Fixed class represents a fixed-point number with 8 fractional bits
// it provides constructors from int and float, conversion back, and stream output
class Fixed
{
private:
	int					rawBits;			// underlying integer storing fixed-point value
	static const int	fractionalBits = 8;	// number of bits for the fractional part

public:
	// default constructor: initializes value to 0
	Fixed();

	// integer constructor: converts int to fixed-point by shifting
	Fixed(int const intValue);

	// float constructor: converts float to fixed-point by multiplying and rounding
	Fixed(float const floatValue);

	// copy constructor
	Fixed(Fixed const &other);

	// copy assignment operator
	Fixed &operator=(Fixed const &other);

	// destructor
	~Fixed();

	// returns the raw fixed-point value (for debugging or low-level access)
	int getRawBits(void) const;

	// sets the raw fixed-point value
	void setRawBits(int const raw);

	// converts fixed-point value to float by dividing by 2^fractionalBits
	float toFloat(void) const;

	// converts fixed-point value to int by shifting right
	int toInt(void) const;
};

// overload of << to output the floating-point representation
std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif
