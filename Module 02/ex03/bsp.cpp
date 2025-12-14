#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed area1 = (a.getX() - point.getX()) * (b.getY() - a.getY()) - (b.getX() - a.getX()) * (a.getY() - point.getY());
	Fixed area2 = (b.getX() - point.getX()) * (c.getY() - b.getY()) - (c.getX() - b.getX()) * (b.getY() - point.getY());
	Fixed area3 = (c.getX() - point.getX()) * (a.getY() - c.getY()) - (a.getX() - c.getX()) * (c.getY() - point.getY());
	if ((area1 > 0 && area2 > 0 && area3 > 0) || (area1 < 0 && area2 < 0 && area3 < 0))
		return true;
	return false;
}