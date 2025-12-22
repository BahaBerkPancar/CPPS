#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
    Point a(-1, 1);
    Point b(-0, -5);
    Point c(2, 4);

    Point p(0, 0);

    if (bsp(a, b, c, p))
        std::cout << "Point is inside the triangle" << std::endl;
    else
        std::cout << "Point is outside the triangle" << std::endl;

    return 0;
}