#include <iostream>
#include <cmath>//roundf
#include "Fixed.hpp"

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed) {
	std::cout << "Copy constructor called" << std::endl;

	*this = fixed;
}

Fixed& Fixed::operator=(const Fixed& fixed) {
	std::cout << "Copy assignment operator called" << std::endl;

	//

	return *this;
}

int Fixed::getRawBits(void) const {
	return _fixedPointNumber;
}

void Fixed::setRawBits(int const raw) {
	_fixedPointNumber = raw;
}

Fixed::Fixed(const int number) {
	std::cout << "Int constructor called" << std::endl;

	_fixedPointNumber = (number << _factionalBits);
}

Fixed::Fixed(const float number) {
	std::cout << "Float constructor called" << std::endl;

	//?
}

//float Fixed::toFloat(void) const {
//	//
//}

//int Fixed::toInt(void) const {
//	//
//}