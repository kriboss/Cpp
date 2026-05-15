#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	a.setRawBits( 10 );
	Fixed b( a );
	std::cout << a.getRawBits() << std::endl;
	Fixed c;
	b.setRawBits( 456 );
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}