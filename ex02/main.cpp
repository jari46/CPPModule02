#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	{
		std::cout << "\n\n   *   ROUND 1   *  " << std::endl;
		Fixed a;
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << b << std::endl;

		std::cout << Fixed::max( a, b ) << std::endl;
	}
	{
		std::cout << "\n\n   *   ROUND 2   *  " << std::endl;
		Fixed a(1);
		Fixed b(42.42f);
		Fixed c(42.42f);

		if (b > a)
			std::cout << "b is grerater than a" << std::endl;
		if (a < b)
			std::cout << "a is less than b" << std::endl;
		if (b >= a)
			std::cout << "b greater than or equal to a" << std::endl;
		if (b >= c)
			std::cout << "b greater than or equal to c" << std::endl;
		if (a <= b)
			std::cout << "a greater than or equal to b" << std::endl;
		if (b <= c)
			std::cout << "b greater than or equal to c" << std::endl;
		if (b == c)
			std::cout << "b equal to c" << std::endl;
		if (a != b)
			std::cout << "a is not equal to b" << std::endl;
	}
	{
		std::cout << "\n\n   *   ROUND 3   *  " << std::endl;
		Fixed const a( Fixed( 5.05f ) + Fixed( 2 ) );
		std::cout << a << std::endl;

		Fixed const b( Fixed( 5.05f ) - Fixed( 2 ) );
		std::cout << b << std::endl;

		Fixed const c( Fixed( 5.05f ) / Fixed( 2 ) );
		std::cout << c << std::endl;
	}
	{
		std::cout << "\n\n   *   ROUND 4   *  " << std::endl;
		Fixed a;
		std::cout << a << std::endl;
		std::cout << --a << std::endl;
		std::cout << a << std::endl;
		std::cout << a-- << std::endl;
		std::cout << a << std::endl;
	
	}
	return 0;
}