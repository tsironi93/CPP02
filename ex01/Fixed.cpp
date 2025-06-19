/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:06:16 by itsiros           #+#    #+#             */
/*   Updated: 2025/05/26 12:46:09 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"
#include <iostream>
#include <ostream>

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
	//std::cout << "getRawBits member function called" << std::endl;
	return this->_fpNumber;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fpNumber = raw;
}

Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	_fpNumber = intValue << _frBits;
}

Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	_fpNumber = roundf(floatValue * (1 << _frBits));
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(_fpNumber) / (1 << _frBits);
}

int Fixed::toInt(void) const
{
	return _fpNumber >> _frBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return  out;
}
