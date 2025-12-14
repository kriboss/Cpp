#include "Fixed.hpp"

Fixed& Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
}

Fixed& Fixed::operator++() {
	++this->value;
	return *this;
}

Fixed& Fixed::operator--() {
	--this->value;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	this->value++;
	return temp;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	this->value--;
	return temp;
}

bool Fixed::operator>(const Fixed &other) const {
	return this->value > other.value;
}

bool Fixed::operator<(const Fixed &other) const {
	return this->value < other.value;
}

bool Fixed::operator>=(const Fixed &other) const {
	return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed &other) const {
	return this->value <= other.value;
}

bool Fixed::operator==(const Fixed &other) const {
	return this->value == other.value;
}

bool Fixed::operator!=(const Fixed &other) const {
	return this->value != other.value;
}

Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->getRawBits() + other.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->getRawBits() - other.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result;
	long temp = static_cast<long>(this->getRawBits()) * static_cast<long>(other.getRawBits());
	result.setRawBits(static_cast<int>(temp >> bits));
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed result;
	long temp = (static_cast<long>(this->getRawBits()) << bits) / static_cast<long>(other.getRawBits());
	result.setRawBits(static_cast<int>(temp));
	return result;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}

void Fixed::setRawBits( int const raw ) {
	this->value = raw;
}

int Fixed::getRawBits( void ) const {
	return this->value;
}

float Fixed::toFloat( void ) const {
	return static_cast<float>(this->value) / (1 << bits);
}

int Fixed::toInt( void ) const {
	return this->value >> bits;
}

Fixed::Fixed() : value(0) {
}

Fixed::Fixed( const int n ) {
	this->value = n << bits;
}

Fixed::Fixed( const float f ) {
	this->value = roundf(f * (1 << bits));
}

Fixed::Fixed(const Fixed &other) {
	this->value = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &other) {
	if (this != &other) {
		this->value = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
}