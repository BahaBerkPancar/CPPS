#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

class PmergeMe {
private:
  std::vector<int> v_data;
  std::deque<int> d_data;

  template <typename Container>
  void printContainer(const Container &data, const std::string &str) {
    std::cout << str;
    for (size_t i = 0; i < data.size() && i < 5; ++i) {
      std::cout << " " << data[i];
    }
    if (data.size() > 5)
      std::cout << " [...]";
    std::cout << std::endl;
  }

  template <typename Container>
  void insertionSort(Container &data, size_t start, size_t end) {
    for (size_t i = start + 1; i <= end; i++) {
      typename Container::value_type key = data[i];
      size_t j = i;
      while (j > start && data[j - 1] > key) {
        data[j] = data[j - 1];
        j--;
      }
      data[j] = key;
    }
  }

  template <typename Container>
  void fordJohnsonSort(Container &data) {
    size_t n = data.size();
    if (n <= 1)
      return;
    if (n <= 10) {
      insertionSort(data, 0, n - 1);
      return;
    }
    Container larger;
    Container smaller;
    bool odd = (n % 2 != 0);
    typename Container::value_type oddElement = 0;
    if (odd)
      oddElement = data[n - 1];
    for (size_t i = 0; i < (n - (odd ? 1 : 0)) / 2; i++) {//
      size_t num = i * 2;
      if (data[num] > data[num + 1]) {
        smaller.push_back(data[num]);
        larger.push_back(data[num + 1]);
      }
      else {
        smaller.push_back(data[num]);
        larger.push_back(data[num + 1]);
      }
    }
    fordJohnsonSort(larger);
    Container result = larger;
    for (size_t i = 0; i < smaller.size(); i++) {
      typename Container::iterator pos = std::lower_bound(result.begin(), result.end(), smaller[i]);
      result.insert(pos, smaller[i]);
    }
    if (odd) {
      typename Container::iterator pos = std::lower_bound(result.begin(), result.end(), oddElement);
      result.insert(pos, oddElement);
    }
    data = result;
  }

  bool isValidNumber(const std::string &str);

public:
  PmergeMe();
  ~PmergeMe();
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);
  void parseInput(int argc, char **argv);
  void sortAndMeasure();
};

#endif
