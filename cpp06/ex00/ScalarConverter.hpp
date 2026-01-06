#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <climits>

class ScalarConverter {
	private:
		static bool isSpecial(const std::string& input);
		static bool isChar(const std::string& input);
		static bool isInt(const std::string& input);
		static bool isFloat(const std::string& input);
		static bool isDouble(const std::string& input);
		ScalarConverter();
		ScalarConverter(const std::string& input);
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
	
public:

	static void convert(const std::string& input);
};
#endif