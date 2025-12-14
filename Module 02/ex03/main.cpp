#include "Point.hpp"

int main( void ) {
	Point a;
	Point b;
	Point c;

	a = Point(0.0f, 0.0f);
	b = Point(5.0f, 0.0f);
	c = Point(2.5f, 5.0f);
	Point const point(6.5f, 2.5f);
	if (bsp(a, b, c, point))
		std::cout << "The point is inside the triangle." << std::endl;
	else
		std::cout << "The point is outside the triangle." << std::endl;

	return 0;
}