
#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(float x, float y) : _x(x), _y(y) {}

Point::Point(const Point &Point) : _x(Point._x), _y(Point._y) {}

Point &Point::operator=(const Point &Point)
{
    (void)Point;
    return *this;
}

Point::~Point() {}

const Fixed	&Point::getx(void)const
{
	return (this->_x);
}

const Fixed	&Point::gety(void)const
{
	return (this->_y);
}