#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <iostream>
#include <ctime>
#include <cstdlib>

class Span {
private:
    unsigned int        _n;
    std::vector<int>    _vec;
    Span();

public:
    Span(unsigned int n);
    Span(const Span &src);
    Span &operator=(const Span &src);
    ~Span();

    void addNumber(int n);
    int shortestSpan() const;
    int longestSpan() const;
	void print() const;

    template <typename T>
    void addNumbers(T begin, T end) {
        if (_vec.size() + std::distance(begin, end) > _n)
            throw std::runtime_error("out of range");
        _vec.insert(_vec.end(), begin, end);
    }
};

#endif
