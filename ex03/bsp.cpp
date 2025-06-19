/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:55:33 by itsiros           #+#    #+#             */
/*   Updated: 2025/06/19 12:55:59 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"
#include "./Point.hpp"

static Fixed area(Point const a, Point const b, Point const c) {
	// Area of triangle using determinant formula
	return Fixed((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
	              b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
	              c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2.0f).abs();
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed areaABC = area(a, b, c);
	Fixed areaPAB = area(point, a, b);
	Fixed areaPBC = area(point, b, c);
	Fixed areaPCA = area(point, c, a);

	return (areaABC == areaPAB + areaPBC + areaPCA) &&
			areaPAB > Fixed(0) &&
			areaPBC > Fixed(0) &&
			areaPCA > Fixed(0);
}
