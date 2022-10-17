#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
	private:
		int _rawBits;
		static const int _factionalBits = 8;// always be the integer literal 8.

	public:
		/* Orthodox Canonical class form 정통 정식 클래스 형식 */
		Fixed();// Default constructor 기본 생성자
		Fixed(const Fixed& fixed);// copy constructor  복사 생성자
		Fixed& operator=(const Fixed& fixed);// copy assignment operator overload 복사 대입 연산자 오버로딩
		~Fixed();// Destructor 소멸자

		int getRawBits(void) const;// returns the raw(origin) value of the fixed-point value.
		void setRawBits(int const raw);// sets the raw value of the fixed-point number.
};

#endif /* FIXED_HPP */
