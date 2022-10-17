#include <iostream>
#include <cmath>//roundf
#include "Fixed.hpp"

Fixed::Fixed(void) {
	_fixedPointNumber = 0;
}

Fixed::~Fixed(void) {
}

Fixed::Fixed(const Fixed& fixed) {
	*this = fixed;
}

Fixed& Fixed::operator=(const Fixed& fixed) {
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
	_fixedPointNumber = (number << _factionalBits);
}

Fixed::Fixed(const float number) {
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
	return _fixedPointNumber + b.getRawBits();
}

Fixed Fixed::operator-(const Fixed &b) const {
	return _fixedPointNumber - b.getRawBits();
}

Fixed Fixed::operator*(const Fixed &b) const {
	return _fixedPointNumber * b.getRawBits();
}

Fixed Fixed::operator/(const Fixed &b) const {
	return _fixedPointNumber / b.getRawBits();
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
