/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:06:16 by itsiros           #+#    #+#             */
/*   Updated: 2025/05/27 09:35:05 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AnsiColors.hpp"
#include "./Fixed.hpp"
#include <cstdint>
#include <iostream>
#include <ostream>


const char* randomColor() {
    // Array of pointers to color strings
    static const char* colors[] = {
        BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE,
        BRIGHT_BLACK, BRIGHT_RED, BRIGHT_GREEN, BRIGHT_YELLOW, BRIGHT_BLUE, BRIGHT_MAGENTA, BRIGHT_CYAN, BRIGHT_WHITE
    };

    static const int numColors = sizeof(colors) / sizeof(colors[0]);

    // Generate random index
    int index = std::rand() % numColors;

    return colors[index];
}


Fixed::Fixed() : _fpNumber(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed (const Fixed &newCopy)
{
	// std::cout << "Copy constructor called" << std::endl;
	//this->_fpNumber = newCopy.getRawBits();
	*this = newCopy;
}

Fixed &Fixed::operator=(const Fixed &newCopy)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &newCopy)
		this->_fpNumber = newCopy.getRawBits();
	return *this;
}

bool Fixed::operator!=(const Fixed &newValue) const
{
	return this->_fpNumber != newValue._fpNumber;
}

bool Fixed::operator==(const Fixed &newValue) const
{
	return this->_fpNumber == newValue._fpNumber;
}

bool Fixed::operator>(const Fixed &newValue) const
{
	return this->_fpNumber > newValue._fpNumber;
}

bool Fixed::operator<(const Fixed &newValue) const
{
	return this->_fpNumber < newValue._fpNumber;
}

bool Fixed::operator<=(const Fixed &newValue) const
{
	return this->_fpNumber <= newValue._fpNumber;
}

bool Fixed::operator>=(const Fixed &newValue) const
{
	return this->_fpNumber >= newValue._fpNumber;
}

Fixed Fixed::operator+(const Fixed &newValue)
{
	Fixed res;

	res.setRawBits(this->_fpNumber + newValue._fpNumber);
	return res;
}

Fixed Fixed::operator-(const Fixed &newValue)
{
	Fixed res;

	res.setRawBits(this->_fpNumber - newValue._fpNumber);
	return res;
}

Fixed Fixed::operator*(const Fixed &newValue)
{
	Fixed	res;
	int64_t	mult;

	mult = static_cast<int64_t>(this->_fpNumber * newValue._fpNumber);
	mult = mult >> _frBits;
	res.setRawBits(static_cast<int>(mult));
	return res;
}

Fixed Fixed::operator/(const Fixed &newValue)
{
	Fixed	res;
	int64_t	div;
	int64_t	num;

	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	
	if (newValue._fpNumber == 0)
	{
		std::cerr << "Division by zero is:" << std::endl;
		for (int i = 0; i < 99999; i++)
			std::cout << randomColor() << " ∞ Trolololo ∞ " << std::endl;;
		return res;
	}

	num = static_cast<int64_t>(this->_fpNumber) << _frBits;
	div = num / newValue._fpNumber;
	res.setRawBits(static_cast<int>(div));
	return res;
}

Fixed &Fixed::operator++()
{
	this->_fpNumber += 1;
	return *this;
}

Fixed &Fixed::operator--()
{
	this->_fpNumber -= 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed	temp;

	temp = *this;
	this->_fpNumber += 1;
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed	temp;

	temp = *this;
	this->_fpNumber -= 1;
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a > b)
		return b;
	return a;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return b;
	return a;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	return b;
}


int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return this->_fpNumber;
}

void Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_fpNumber = raw;
}

Fixed::Fixed(const int intValue)
{
	// std::cout << "Int constructor called" << std::endl;
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
