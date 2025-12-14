#include "Fixed.hpp"

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

float Fixed::toFloat( void ) const {
	return static_cast<float>(this->value) / (1 << bits);
}

int Fixed::toInt( void ) const {
	return this->value >> bits;
}

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int n ) {
	std::cout << "Int constructor called" << std::endl;
	this->value = n << bits;
}

Fixed::Fixed( const float f ) {
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(f * (1 << bits));
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	this->value = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->value = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}