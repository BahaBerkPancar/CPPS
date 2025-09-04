#include "Fixed.hpp"

Fixed::Fixed() : fixed_point(0){
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int i){
	std::cout << "Int constructor called" << std::endl;
	setRawBits(i);
	this->fixed_point = getRawBits();
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed) : fixed_point(fixed.fixed_point){
	std::cout << "Copy Constructor called" << std::endl;
}

Fixed& Fixed:: operator= (const Fixed& fixed){
	std::cout << "Copy Assignment operator called" << std::endl;
	if(this == &fixed)
		return(*this);
	this->fixed_point = fixed.fixed_point;
	return(*this);
}

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->fixed_point);
}

void Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called" << std::endl;
	this->fixed_point = raw;
}