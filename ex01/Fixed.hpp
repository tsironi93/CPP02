/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 11:48:25 by itsiros           #+#    #+#             */
/*   Updated: 2025/05/26 12:40:00 by itsiros          ###   ########.fr       */
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


		Fixed(const int intValue);
		Fixed(const float floatValue);



		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif // !FIXED_HPP
