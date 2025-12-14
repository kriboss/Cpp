#include "Point.hpp"

Fixed const Point::getX() const {
	return this->x;
}

Fixed const Point::getY() const {
	return this->y;
}

Point::Point() : x(0), y(0) {
}

Point::Point(Fixed const x, Fixed const y) : x(x), y(y) {
}

Point::Point(Point const& other) : x(other.x), y(other.y) {
}

Point& Point::operator=(Point const &other) {
	if (this != &other) {
		this->x = other.x;
		this->y = other.y;
	}
	return *this;
}

Point::~Point() {
}

