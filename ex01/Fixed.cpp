#include <iostream>
#include <cmath>//roundf
#include "Fixed.hpp"

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	_rawBits = 0;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed) {
	std::cout << "Copy constructor called" << std::endl;

	*this = fixed;
}

/* operator overloading */
Fixed& Fixed::operator=(const Fixed& fixed) {
	std::cout << "Copy assignment operator called" << std::endl;

	_rawBits = fixed.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const {
	return _rawBits;
}

void Fixed::setRawBits(int const raw) {
	_rawBits = raw;
}

//----------------------- added functions ------------------------//

Fixed::Fixed(const int number) {
	std::cout << "Int constructor called" << std::endl;

	_rawBits = (number << _factionalBits);
}

Fixed::Fixed(const float number) {
	std::cout << "Float constructor called" << std::endl;

	//to make it easier, consider it as number (not bits)
	_rawBits = std::roundf(number * (1 << _factionalBits));
}

/* operator overloading */
std::ostream &operator<<(std::ostream &os, Fixed const &value)
{
    os << value.toFloat();
    return (os);
}

float Fixed::toFloat(void) const {
	return (float)_rawBits / (float)(1 << _factionalBits);
}

int Fixed::toInt(void) const {
	return _rawBits >> _factionalBits;
}