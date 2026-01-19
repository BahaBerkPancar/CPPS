#pragma once

#include <iostream>

template <typename T>
void iter(T *array, size_t length, void (*f)(T &)) {
	for (size_t i = 0; i < length; ++i) {
		f(array[i]);
	}
}

template <typename T>
void print(T &element) {
	std::cout << "Element : "<< element << std::endl;
}

template <typename T>
void increment(T &element) {
	++element;
}

template <typename T>
void square(T &element) {
    element = element * element;
}

template <typename T>
void toupper(T &c) {
    c = static_cast<T>(::toupper(static_cast<unsigned char>(c)));
}

inline void toupper(std::string &s) {
    for (size_t i = 0; i < s.length(); i++) {
        s[i] = static_cast<char>(::toupper(static_cast<unsigned char>(s[i])));
    }
}

template <typename T>
void _double(T &element) {
	element *= 2;
}

