#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char **av) {
  try {
    PmergeMe sorter;
    sorter.parseInput(ac, av);
    sorter.sortAndMeasure();
  } catch (std::exception &e) {
    return (std::cerr << e.what() << std::endl, 1);
  }
  return (0);
}
