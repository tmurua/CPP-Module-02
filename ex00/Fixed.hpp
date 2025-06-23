/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:56:39 by tmurua            #+#    #+#             */
/*   Updated: 2025/06/23 10:59:35 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

// the Fixed class implements a fixed-point number
// in Orthodox Canonical Form (default ctor, copy ctor,
// assignment operator, destructor).
class Fixed
{
private:
	int					rawBits;			// stores the fixed-point integer value
	static const int	fractionalBits = 8;	// number of fractional bits (constant)

public:
	// default constructor: initializes rawBits to 0
	Fixed();

	// copy constructor: creates a new Fixed from an existing one
	Fixed(const Fixed &other);

	// copy assignment operator: assign one Fixed to another
	Fixed &operator=(const Fixed &other);

	// destructor: called when a Fixed object goes out of scope
	~Fixed();

	// accessor: returns the raw integer value (fixed-point representation)
	int  getRawBits(void) const;

	// mutator: sets the raw integer value
	void setRawBits(int const raw);
};

#endif
