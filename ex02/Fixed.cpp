#include <iostream>
#include <cmath>//roundf
#include "Fixed.hpp"

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	_fixedPointNumber = 0;
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

	_fixedPointNumber = fixed.getRawBits();
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
	
	_fixedPointNumber = std::roundf(number * (1 << _factionalBits));
}

std::ostream &operator<<(std::ostream &os, Fixed const &value) {
    os << value.toFloat();
    return (os);
}

float Fixed::toFloat(void) const {
	return (float)_fixedPointNumber / (float)(1 << _factionalBits);
}

int Fixed::toInt(void) const {
	return _fixedPointNumber >> _factionalBits;
}


//----------------------- added functions ------------------------//


/* comparison operators: >, <, >=, <=, ==, != */
bool Fixed::operator>(const Fixed &b) const {
	return _fixedPointNumber > b.getRawBits();
}

bool Fixed::operator<(const Fixed &b) const {
	return _fixedPointNumber < b.getRawBits();
}

bool Fixed::operator>=(const Fixed &b) const {
	return _fixedPointNumber >= b.getRawBits();
}

bool Fixed::operator<=(const Fixed &b) const {
	return _fixedPointNumber <= b.getRawBits();
}

bool Fixed::operator==(const Fixed &b) const {
	return _fixedPointNumber == b.getRawBits();
}

bool Fixed::operator!=(const Fixed &b) const {
	return _fixedPointNumber != b.getRawBits();
}

/* arithmetic operators: +, -, *, / */
Fixed Fixed::operator+(const Fixed &b) const {
	Fixed newFixed(toFloat() + b.toFloat());
	return newFixed;
}

Fixed Fixed::operator-(const Fixed &b) const {
	Fixed newFixed(toFloat() - b.toFloat());
	return newFixed;
}

Fixed Fixed::operator*(const Fixed &b) const {
	Fixed newFixed(toFloat() * b.toFloat());
	return newFixed;
}

Fixed Fixed::operator/(const Fixed &b) const {
	Fixed newFixed(toFloat() / b.toFloat());
	return newFixed;
}

/* pre-increment/decrement operators: ++a, --a */
Fixed &Fixed::operator++() {
	_fixedPointNumber = _fixedPointNumber + 1;
	return *this;
}

Fixed &Fixed::operator--() {
	_fixedPointNumber = _fixedPointNumber - 1;
	return *this;
}

/* post-increment/decrement operators: a++, a-- */
const Fixed Fixed::operator++(int) {
	const Fixed meCopied(*this);
	_fixedPointNumber = _fixedPointNumber + 1;
	return meCopied;
}

const Fixed Fixed::operator--(int) {
	const Fixed meCopied(*this);
	_fixedPointNumber = _fixedPointNumber + 1;
	return meCopied;
}
