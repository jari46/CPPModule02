#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
	private:
		int _fixedPointNumber;
		static const int _factionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed& fixed);
		Fixed& operator=(const Fixed& fixed);
		~Fixed();
		
		int getRawBits(void) const;
		void setRawBits(int const raw);

		/* 1. GET some other kinds of number, 
		** CONVERTs it to the corresponding FIXED-PONT value,
		** and STORE it */
		Fixed(const int number);
		Fixed(const float number);

		/* 2. CONVERTs its FIXED-PONT value to the OTHER value,
		** and RETURN it. */
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, Fixed const &value);

#endif /* FIXED_HPP */
