#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cctype>
class RPN
{
private:
	void performOperation(std::stack<int> &stack, char c);
public:
	RPN();
	~RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	int Process(const std::string &str);
};

#endif
