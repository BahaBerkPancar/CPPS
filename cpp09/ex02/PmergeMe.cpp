#include "PmergeMe.hpp"
#include <iomanip>
#include <limits>
#include <stdexcept>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : v_data(other.v_data), d_data(other.d_data) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  if (this != &other) {
    v_data = other.v_data;
    d_data = other.d_data;
  }
  return *this;
}

bool PmergeMe::isValidNumber(const std::string &str) {
  if (str.empty())
    return false;

  for (size_t i = 0; i < str.length(); ++i) {
    if (!std::isdigit(str[i]))
      return false;
  }

  char *end;
  long num = std::strtol(str.c_str(), &end, 10);
  if (num > std::numeric_limits<int>::max() || num < 0)
    return false;
  return true;
}

void PmergeMe::parseInput(int ac, char **av) {
  if (ac < 2)
    throw std::runtime_error("Error: No input provided");
  for (int i = 1; i < ac; ++i) {
    std::string str(av[i]);
    if (!isValidNumber(str))
      throw std::runtime_error("Error: Invalid input");
    int num = std::atoi(str.c_str());
    if (num < 0)
      throw std::runtime_error("Error: Negative numbers not allowed");
    v_data.push_back(num);
    d_data.push_back(num);
  }
}

void PmergeMe::sortAndMeasure() {
  printContainer(v_data, "Before:");
  clock_t start = clock();
  fordJohnsonSort(v_data);
  clock_t end = clock();
  double vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
  start = clock();
  fordJohnsonSort(d_data);
  end = clock();
  double deqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
  printContainer(v_data, "After:");
  std::cout << std::fixed << std::setprecision(5);
  std::cout << "Time to process a range of " << v_data.size() << " elements with std::vector : " << vecTime << " us" << std::endl;
  std::cout << "Time to process a range of " << d_data.size() << " elements with std::deque : " << deqTime << " us" << std::endl;
}
