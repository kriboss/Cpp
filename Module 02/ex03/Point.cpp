#include "Point.hpp"

Fixed const Point::getX() const {
	return this->x;
}

Fixed const Point::getY() const {
	return this->y;
}

Point::Point() : x(0), y(0) {
}

Point::Point(float const x, float const y) : x(x), y(y) {
}

Point::Point(Point const& other) : x(other.x), y(other.y) {
}

Point& Point::operator=(Point const &other) {
	(void)other;
	return *this;
}

Point::~Point() {
}

