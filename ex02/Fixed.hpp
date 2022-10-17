#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
	private:
		int _rawBits;
		static const int _factionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed& fixed);
		Fixed& operator=(const Fixed& fixed);
		~Fixed();
		
		int getRawBits(void) const;
		void setRawBits(int const raw);

		Fixed(const int number);
		Fixed(const float number);

		float toFloat(void) const;
		int toInt(void) const;

		/* comparison operators: >, <, >=, <=, ==, != */
	
		bool operator<(const Fixed &b) const;
		bool operator>=(const Fixed &b) const;
		bool operator<=(const Fixed &b) const;
		bool operator==(const Fixed &b) const;
		bool operator!=(const Fixed &b) const;

		/* arithmetic operators: +, -, *, / */
		Fixed operator+(const Fixed &b) const;
		Fixed operator-(const Fixed &b) const;
		Fixed operator*(const Fixed &b) const;
		Fixed operator/(const Fixed &b) const;

		/* increment/decrement operators: ++a, a++, --a, a-- */
		Fixed &operator++();
		Fixed &operator--();
		const Fixed operator++(int);
		const Fixed operator--(int);

		/* returns a reference to the smallest/greatest one */
		static Fixed &min(Fixed &num1, Fixed &num2);
		static const Fixed &min(const Fixed &num1, const Fixed &num2);
		static Fixed &max(Fixed &num1, Fixed &num2);
		static const Fixed &max(const Fixed &num1, const Fixed &num2);
};

std::ostream &operator<<(std::ostream &os, Fixed const &value);

#endif /* FIXED_HPP */
