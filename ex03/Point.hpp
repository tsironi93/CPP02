/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 09:46:40 by itsiros           #+#    #+#             */
/*   Updated: 2025/06/03 10:07:31 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "./Fixed.hpp"

class	Point
{
	private:
		Fixed const _x;
		Fixed const _y;

	public:
		Point();
		Point(float a, float b);
		~Point();

		Point(const Point &other);
		Point &operator=(Point const &other);

		Fixed getX() const;
		Fixed getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif // !POINT_HPP
