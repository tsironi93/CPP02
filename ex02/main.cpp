/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 11:36:44 by itsiros           #+#    #+#             */
/*   Updated: 2025/05/27 09:41:07 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;


	// a = 15;
	// b = 2;
	//
	// std::cout << std::boolalpha;
	// std::cout << a << " != " << b << " is " << (a!=b) << std::endl;
	// std::cout << a << " == " << b << " is " << (a==b) << std::endl;
	// std::cout << a << " >= " << b << " is " << (a>=b) << std::endl;
	// std::cout << a << " <= " << b << " is " << (a<=b) << std::endl;
	// std::cout << a << " > " << b << " is " << (a>b) << std::endl;
	// std::cout << a << " < " << b << " is " << (a<b) << std::endl;
	//
	// std::cout << a << " + " << b << " is " << (a+b) << std::endl;
	// std::cout << a << " - " << b << " is " << (a-b) << std::endl;
	// std::cout << a << " * " << b << " is " << (a*b) << std::endl;
	// std::cout << a << " / " << b << " is " << (a/b) << std::endl;
	//
	// Fixed c = 0;
	//
	//std::cout << a << " / " << b << " is " << (a/c) << std::endl;

	// Fixed d;
	// a = 42;
	// d = 42;
	// std::cout << Fixed::min(a ,d) << std::endl;

	return 0;
}
