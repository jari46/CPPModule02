#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
	private:
		int _fixedPointNumber;
		static const int _factionalBits;// always be the integer literal 8.

	public:
		Fixed();
		Fixed(const Fixed& fixed);// copy constructor
		Fixed& operator=(const Fixed& fixed);// copy assignment operator overload
		~Fixed();

		int getRawBits(void) const;// returns the raw(origin) value of the fixed-point value.
		void setRawBits(int const raw);// sets the raw value of the fixed-point number.
};

#endif /* FIXED_HPP */
