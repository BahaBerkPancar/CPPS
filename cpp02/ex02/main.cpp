#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}

/*
int main()
{
    Fixed a;
    Fixed b(10);
    Fixed c(42.42f);
    Fixed d(b);

    a = Fixed(5.5f);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;

    std::cout << "toInt and toFloat" << std::endl;
    std::cout << a.toInt() << std::endl;
    std::cout << c.toFloat() << std::endl;

    std::cout << "comparison" << std::endl;
    std::cout << (a < b) << std::endl;
    std::cout << (a > b) << std::endl;
    std::cout << (a <= b) << std::endl;
    std::cout << (a >= b) << std::endl;
    std::cout << (a == b) << std::endl;
    std::cout << (a != b) << std::endl;
    std::cout << (a + b) << std::endl;
    std::cout << (b - a) << std::endl;
    std::cout << (a * b) << std::endl;
    std::cout << (b / a) << std::endl;

    Fixed x(1);

    std::cout << "incrementations" << std::endl;
    std::cout << x++ << std::endl;
    std::cout << x << std::endl;
    std::cout << ++x << std::endl;
    std::cout << x << std::endl;

    std::cout << "decrementations" << std::endl;
    std::cout << x-- << std::endl;
    std::cout << x << std::endl;
    std::cout << --x << std::endl;
    std::cout << x << std::endl;

    Fixed e(3);
    Fixed f(7);

    std::cout << "min and max" << std::endl;
    std::cout << Fixed::min(e, f) << std::endl;
    std::cout << Fixed::max(e, f) << std::endl;

    const Fixed g(100);
    const Fixed h(200);

    std::cout << Fixed::min(g, h) << std::endl;
    std::cout << Fixed::max(g, h) << std::endl;

    return 0;
}
*/