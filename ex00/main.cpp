#include <iostream>
#include "Fixed.hpp"

/* see with [Fixed.cpp] */

int main( void ) {
	Fixed a;// Default constructor called
	Fixed b(a);// Copy constructor called -> ...
	Fixed c;// Default constructor called

	c = b;// Copy assignment operator called -> ...


	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	
	return 0;