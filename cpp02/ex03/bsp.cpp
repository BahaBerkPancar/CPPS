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
    Fixed zero = Fixed(0);
    Fixed d1 = cross(a, b, point);
    Fixed d2 = cross(b, c, point);
    Fixed d3 = cross(c, a, point);
    bool has_neg = false;
    bool has_pos = false;

    if (d1 == zero || d2 == zero || d3 == zero)
        return false;
    if ((d1 < zero) || (d2 < zero) || (d3 < zero))
        has_neg = true;
    if ((d1 > zero) || (d2 > zero) || (d3 > zero))
        has_pos = true;
    return !(has_neg && has_pos);
}
    