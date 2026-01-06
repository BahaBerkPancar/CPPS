#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isSpecial(const std::string& input) {
    if (input == "nan" || input == "nanf" ||
        input == "inf" || input == "inff" ||
        input == "+inf" || input == "+inff" ||
        input == "-inf" || input == "-inff") {
        return true;
    }
    return false;
}

bool ScalarConverter::isChar(const std::string& input) {
    if (input.empty())
        return false;
    if (input.length() != 1 || std::isdigit(input[0]))
        return false;
    return std::isprint(input[0]);
}

bool ScalarConverter::isInt(const std::string& input) {
    if (input.empty())
        return false;
    size_t i = 0;
    if (input[i] == '+' || input[i] == '-') {
        i++;
    }
    if (i == input.length())
        return false;
    for (; i < input.length(); i++) {
        if (!std::isdigit(input[i]))
            return false;
    }
    char* end;
    long val = std::strtol(input.c_str(), &end, 10);
    if (val < INT_MIN || val > INT_MAX) {
        return false;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string& input) {
    if (input.empty())
        return false;
    if (input == "nanf" || input == "+inff" || input == "-inff")
        return true;
    size_t i = 0;
    bool dot = false;
    if (input[i] == '+' || input[i] == '-')
        i++;
    for (; i < input.length(); i++) {
        if (input[i] == '.') {
            if (dot)
                return false;
            dot = true;
        } 
        else if (!std::isdigit(input[i]) && input[i] != 'f') 
            return false;
    }
    if (input.back() != 'f' || input.length() < 2)
        return false;
    return true;
}

bool ScalarConverter::isDouble(const std::string& input) {
    if (input.empty())
        return false;
    size_t i = 0;
    bool dot = false;
    if (input[i] == '+' || input[i] == '-')
        i++;
    for (; i < input.length(); i++) {
        if (input[i] == '.') {
            if (dot)
                return false;
            dot = true;
        } 
        else if (!std::isdigit(input[i])) 
            return false;
    }
    return true;
}

static void print(double val) {
    std::cout << "char: ";
    if (val < 0 || val > 127 || std::isnan(val) || std::isinf(val))
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(val)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(val) << "'" << std::endl;

    std::cout << "int: ";
    if (val < static_cast<double>(INT_MIN) || val > static_cast<double>(INT_MAX) || std::isnan(val) || std::isinf(val))
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(val) << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
    std::cout << "double: " << val << std::endl;
}

void ScalarConverter::convert(const std::string& input) {
    if (isSpecial(input)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (input.find("f") != std::string::npos || input == "nanf") {
            std::cout << "float: " << input << std::endl;
            std::string d = input;
            if (input == "nanf") d = "nan";
            else d = input.substr(0, input.length() - 1);
            std::cout << "double: " << d << std::endl;
        } else {
            std::cout << "float: " << input << "f" << std::endl;
            std::cout << "double: " << input << std::endl;
        }
        return;
    }

    if (isChar(input)) {
        char c = input[0];
        print(static_cast<double>(c));
    } else if (isInt(input)) {
        int i = std::atoi(input.c_str());
        print(static_cast<double>(i));
    } else if (isFloat(input)) {
        float f = std::atof(input.c_str());
        print(static_cast<double>(f));
    } else if (isDouble(input)) {
        double d = std::atof(input.c_str());
        print(d);
    } else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
}