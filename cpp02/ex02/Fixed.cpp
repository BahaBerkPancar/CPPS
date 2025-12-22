#include "Fixed.hpp"

Fixed::Fixed() : fixed_point(0){
}

Fixed::Fixed(const int i) {
    this->fixed_point = i * (1 << bits);
}

Fixed::Fixed(const float floating_point){
	this->fixed_point = roundf(floating_point * (1 << bits));
}

Fixed::~Fixed(){
}

Fixed::Fixed(const Fixed& fixed) : fixed_point(fixed.fixed_point){
}

Fixed& Fixed:: operator= (const Fixed& fixed){
	if(this == &fixed)
		return(*this);
	this->fixed_point = fixed.fixed_point;
	return(*this);
}

int Fixed::getRawBits(void) const{
	return(this->fixed_point);
}

void Fixed::setRawBits(int const raw){
	this->fixed_point = raw;
}

float Fixed::toFloat( void ) const{
	return (fixed_point / static_cast<float>(1 << bits));
}

int Fixed::toInt( void ) const{
	return (this->fixed_point >> bits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& f)
{
    out << f.toFloat();
    return out;
}

bool	Fixed::operator<(const Fixed& fixed) const{
	return (this->fixed_point < fixed.fixed_point);
}

bool	Fixed::operator>(const Fixed& fixed) const{
	return (this->fixed_point > fixed.fixed_point);
}

bool	Fixed::operator<=(const Fixed& fixed) const{
	return (this->fixed_point <= fixed.fixed_point);
}

bool	Fixed::operator>=(const Fixed& fixed) const{
	return (this->fixed_point >= fixed.fixed_point);
}

bool	Fixed::operator==(const Fixed& fixed) const{
	return (this->fixed_point == fixed.fixed_point);
}

bool	Fixed::operator!=(const Fixed& fixed) const{
		return (this->fixed_point != fixed.fixed_point);
}

Fixed	Fixed::operator+(const Fixed& fixed) const{
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& fixed) const{
	return(Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator*(const Fixed& fixed) const {
    return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed& fixed) const{
    return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed Fixed::operator++(int){
	Fixed old(*this);
	this->fixed_point++;
	return(old);
}

Fixed& Fixed::operator++(){
	this->fixed_point++;
	return (*this);
}

Fixed Fixed::operator--(int){
	Fixed old(*this);
	this->fixed_point--;
	return (old);
}

Fixed& Fixed::operator--(){
	this->fixed_point--;
	return (*this);
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second) {
    return (first.getRawBits() < second.getRawBits() ? first : second);
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second) {
    return (first.getRawBits() > second.getRawBits() ? first : second);
}

Fixed& Fixed::min(Fixed& first, Fixed& second) {
    return (first.getRawBits() < second.getRawBits() ? first : second);
}

Fixed& Fixed::max(Fixed& first, Fixed& second) {
    return (first.getRawBits() > second.getRawBits() ? first : second);
}