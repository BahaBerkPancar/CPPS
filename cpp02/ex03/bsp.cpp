#include "Point.hpp"

static Fixed cross(const Point& a, const Point& b, const Point& p)
{
    Fixed abx = b.getx() - a.getx();
    Fixed aby = b.gety() - a.gety();
    Fixed apx = p.getx() - a.getx();
    Fixed apy = p.gety() - a.gety();

    return abx * apy - aby * apx;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed zero(0);
    Fixed d1 = cross(a, b, point);
    Fixed d2 = cross(b, c, point);
    Fixed d3 = cross(c, a, point);

    if (d1 == zero || d2 == zero || d3 == zero)
        return false;
    return ((d1 > zero && d2 > zero && d3 > zero) || 
            (d1 < zero && d2 < zero && d3 < zero));
}