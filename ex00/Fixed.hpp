/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 11:48:25 by itsiros           #+#    #+#             */
/*   Updated: 2025/05/25 13:47:38 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Fixed 
{
	private:
		int	_fpNumber;
		static const int	_frBits = 8;

	public:
		Fixed();
		~Fixed();

		// Copy Constractor
		Fixed(const Fixed &newCopy);

		// Copy Assignment Constractor
		Fixed &operator = (const Fixed &newCopy);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

};
