#include "Span.hpp"
#include <climits>

Span::Span() : _n(0) {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span &other) : _n(other._n), _vec(other._vec) {}

Span::~Span() {}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        this->_n = other._n;
        this->_vec = other._vec;
    }
    return *this;
}


void Span::addNumber(int n) {
    if (_vec.size() >= _n)
        throw std::runtime_error("out of range");
    _vec.push_back(n);
}

int Span::shortestSpan() const {
    if (_vec.size() < 2)
        throw std::runtime_error("more than 2 numbers are needed for a span");

    std::vector<int> sorted = _vec;
    std::sort(sorted.begin(), sorted.end());

    int min = INT_MAX;
    for (size_t i = 0; i < sorted.size() - 1; ++i) {
        int diff = sorted[i + 1] - sorted[i];
        if (diff < min)
            min = diff;
    }
    return min;
}

int Span::longestSpan() const {
    if (_vec.size() < 2)
		throw std::runtime_error("more than 2 numbers are needed for a span");
    int min = *std::min_element(_vec.begin(), _vec.end());
    int max = *std::max_element(_vec.begin(), _vec.end());

    return max - min;
}

void Span::print() const {
    std::cout << "Span : ";
    for (std::vector<int>::const_iterator it = _vec.begin(); it != _vec.end(); ++it) {
        std::cout << "[" << *it << "] ";
    }
    std::cout << std::endl;
}
