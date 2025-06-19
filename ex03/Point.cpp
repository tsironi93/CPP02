/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 09:53:16 by itsiros           #+#    #+#             */
/*   Updated: 2025/06/19 12:56:05 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Point.hpp"
#include "Fixed.hpp"


Point::Point () : _x{0}, _y{0} {}

Point::Point (float a, float b) : _x(Fixed(a)), _y(Fixed(b)) {}

Point::Point (const Point &other) : _x(other._x), _y(other._y) {}

Point &Point::operator=(const Point &other) { (void)other; return *this; }

Point::~Point() {}

Fixed Point::getX() const { return _x; }
Fixed Point::getY() const { return _y; }
