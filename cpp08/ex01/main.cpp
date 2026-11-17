#include "Span.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

int randLimit() {
	return std::rand() % 30;
}

int main(int ac, char **) {
	if(ac != 1)
		return (std::cout << "Usage: ./span" << std::endl, -1);

	std::srand(std::time(0));

	Span sp(5);
	std::vector<int> smallVec(5);
	std::generate(smallVec.begin(), smallVec.end(), randLimit);
	sp.addNumbers(smallVec.begin(), smallVec.end());
	sp.print();
	std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest: " << sp.longestSpan() << std::endl;

	Span Span(10000);
	std::vector<int> randomNums(10000);
	std::generate(randomNums.begin(), randomNums.end(), std::rand);
	Span.addNumbers(randomNums.begin(), randomNums.end());
	std::cout << "Shortest: " << Span.shortestSpan() << std::endl;
	std::cout << "Longest: " << Span.longestSpan() << std::endl;
	return 0; 
}
