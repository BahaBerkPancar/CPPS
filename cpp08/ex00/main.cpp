#include "easyfind.hpp"
#include <vector>
#include <list>

int main(int ac, char **) {
	if(ac != 1)
		return std::cout << "Usage: ./easyfind" << std::endl, -1;
		
    std::vector<int> vec;

	vec.push_back(42);
	int values[] = {0, 10, 20, 30, 40, 50};
	vec.assign(values, values + 5);
    
	for (int i = 0; i < 6; ++i)
        vec.push_back(i * 13);

	std::cout << "vec : ";
	print(vec);
    try {
        std::vector<int>::iterator it = easyfind(vec, 20);
        std::cout << "found: " << *it << std::endl;
        easyfind(vec, 42);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
	lst.insert(lst.end(), vec.begin(), vec.begin() + 5);

	std::cout << "lst : ";
	print(lst);
    try {
        std::list<int>::iterator it = easyfind(lst, 3);
        std::cout << "found: " << *it << std::endl;
        easyfind(lst, 100);
    } catch (const std::exception& e) {
        std::cerr << "error: " << e.what() << std::endl;
    }

    const std::vector<int> c_vec(vec);
    try {
        std::vector<int>::const_iterator it = easyfind(c_vec, 32);
        std::cout << "Const vector found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Const error: " << e.what() << std::endl;
    }

    return 0;
}
