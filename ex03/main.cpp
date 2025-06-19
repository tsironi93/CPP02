/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:22:50 by itsiros           #+#    #+#             */
/*   Updated: 2025/06/03 10:48:10 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main()
{
	Point a(0.0f, 0.0f);
	Point b(5.0f, 0.0f);
	Point c(0.0f, 5.0f);

	Point inside(1.0f, 1.0f);
	Point onEdge(0.0f, 2.5f);
	Point vertex(0.0f, 0.0f);
	Point outside(5.0f, 5.0f);

	std::cout << "Inside: " << bsp(a, b, c, inside) << std::endl;
	std::cout << "On edge: " << bsp(a, b, c, onEdge) << std::endl;
	std::cout << "Vertex: " << bsp(a, b, c, vertex) << std::endl;
	std::cout << "Outside: " << bsp(a, b, c, outside) << std::endl;

	return 0;
}

