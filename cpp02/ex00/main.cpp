#include "Fixed.Hpp"

int main( void ) {
	Fixed a;
	Fixed b(a);
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return(0);
}

// int main()
// {
//     std::cout << "---- Default construction ----" << std::endl;
//     Fixed a;
//     std::cout << "a.getRawBits(): " << a.getRawBits() << std::endl;

//     std::cout << "\n---- Using setRawBits ----" << std::endl;
//     a.setRawBits(42);
//     std::cout << "a.getRawBits() after setRawBits(42): " << a.getRawBits() << std::endl;

//     std::cout << "\n---- Copy constructor ----" << std::endl;
//     Fixed b(a); // copy a into b
//     std::cout << "b.getRawBits(): " << b.getRawBits() << std::endl;

//     std::cout << "\n---- Copy assignment operator ----" << std::endl;
//     Fixed c;
//     c = a; // assign a to c
//     std::cout << "c.getRawBits(): " << c.getRawBits() << std::endl;

//     std::cout << "c.getRawBits() after self-assignment: " << c.getRawBits() << std::endl;

//     std::cout << "\n---- Modifying copy and checking independence ----" << std::endl;
//     b.setRawBits(100);
//     std::cout << "b.getRawBits() after setRawBits(100): " << b.getRawBits() << std::endl;
//     std::cout << "a.getRawBits() should still be 42: " << a.getRawBits() << std::endl;

//     return 0;
// }
