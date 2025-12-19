#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class Fixed{

	private:
		int fixed_point;
		static const int bits = 8;
	public:
		Fixed();
		Fixed(const int i);
		Fixed(const float floating_point);
		Fixed(const Fixed& fixed);
		~Fixed();
		Fixed& operator=(const Fixed& fixed);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

		bool operator<(const Fixed& fixed) const;
		bool operator>(const Fixed& fixed) const;
		bool operator<=(const Fixed& fixed) const;
		bool operator>=(const Fixed& fixed) const;
		bool operator==(const Fixed& fixed) const;
		bool operator!=(const Fixed& fixed) const;
		Fixed operator+(const Fixed& fixed) const;
		Fixed operator-(const Fixed& fixed) const;
		Fixed operator*(const Fixed& fixed) const;
		Fixed operator/(const Fixed& fixed) const;
		Fixed& operator++();
		Fixed& operator--();
		Fixed operator++(int);
		Fixed operator--(int);
		static const Fixed& min(const Fixed& first, const Fixed& second);
		static const Fixed& max(const Fixed& first, const Fixed& second);
		static Fixed& min(Fixed& first, Fixed& second);
		static Fixed& max(Fixed& first, Fixed& second);
};

std::ostream& operator<<(std::ostream& out, const Fixed& f);

#endif
