/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:03:10 by tmurua            #+#    #+#             */
/*   Updated: 2025/06/23 11:06:19 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	// create objects using default and copy constructors
	Fixed a;             // default constructor called
	Fixed b(a);          // copy constructor called
	Fixed c;             // default constructor called

	// use copy assignment operator to assign b to c
	c = b;               // copy assignment operator called

	// retrieve and print raw bits for each Fixed object
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;            // destructors called for c, b, a in reverse order
}
