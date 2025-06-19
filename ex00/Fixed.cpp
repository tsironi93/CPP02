/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:06:16 by itsiros           #+#    #+#             */
/*   Updated: 2025/06/03 14:03:30 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _fpNumber(0)
{
	std::cout << "Default constructor called" << std::endl;
}



Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed (const Fixed &newCopy)
{
	std::cout << "Copy constructor called" << std::endl;
	//this->_fpNumber = newCopy.getRawBits();
	*this = newCopy;
}

Fixed &Fixed::operator=(const Fixed &newCopy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &newCopy)
		this->_fpNumber = newCopy.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fpNumber;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fpNumber = raw;
}
