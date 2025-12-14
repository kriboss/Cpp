#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
	private:
		Fixed x;
		Fixed y;
	public:
		Point();
		Point(Fixed const x, Fixed const y);
		Point(Point const& other);
		Point& operator=( Point const& other);
		Fixed const getX() const;
		Fixed const getY() const;
		~Point();
} ;

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif