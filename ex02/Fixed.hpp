/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 11:48:25 by itsiros           #+#    #+#             */
/*   Updated: 2025/05/27 09:34:01 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <ostream>

class Fixed 
{
	private:
		int					_fpNumber;
		static const int	_frBits = 8;

	public:
		Fixed();
		~Fixed();

		// Copy Constractor
		Fixed(const Fixed &newCopy);

		// Copy Assignment Constractor
		Fixed &operator = (const Fixed &newCopy);


		bool operator > (const Fixed &newCopy) const;
		bool operator < (const Fixed &newCopy) const;
		bool operator >= (const Fixed &newCopy) const;
		bool operator <= (const Fixed &newCopy) const;
		bool operator == (const Fixed &newCopy) const;
		bool operator != (const Fixed &newCopy) const;

		Fixed operator + (const Fixed &newCopy);
		Fixed operator - (const Fixed &newCopy);
		Fixed operator * (const Fixed &newCopy);
		Fixed operator / (const Fixed &newCopy);

		Fixed &operator ++();
		Fixed &operator --();
		Fixed operator ++(int);
		Fixed operator --(int);

		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);

		Fixed(const int intValue);
		Fixed(const float floatValue);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif // !FIXED_HPP
