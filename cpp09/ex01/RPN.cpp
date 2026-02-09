#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) {
	(void)other;
}

RPN &RPN::operator=(const RPN &other)
{
	(void)other;
	return *this;
}

int RPN::Process(const std::string &str)
{
	std::stack<int> stack;
	std::istringstream iss(str);
	std::string tmp;
	std::string operators = "+-*/";
	while (iss >> tmp)
	{
		if (tmp.length() == 1 && std::isdigit(tmp[0]))
			stack.push((tmp[0] - '0'));
		else if (tmp.length() == 1 && operators.find(tmp[0]) != std::string::npos)
			performOperation(stack, tmp[0]);
		else
			throw std::invalid_argument("Error: Invalid token in expression");
	}
	if (stack.size() != 1)
		throw std::runtime_error("Error: input has too many values");
	return stack.top();
}

void RPN::performOperation(std::stack<int> &stack, char c)
{
	if (stack.size() < 2)
		throw std::runtime_error("Error: Insufficient values in expression.");
	int b = stack.top();
	stack.pop();
	int a = stack.top();
	stack.pop();
	switch (c)
	{
	case '+':
		stack.push(a + b);
		break;
	case '-':
		stack.push(a - b);
		break;
	case '*':
		stack.push(a * b);
		break;
	case '/':
		if (b == 0)
			throw std::runtime_error("Error: undefined division");
		else
			stack.push(a / b);
			break;
	default:
		throw std::runtime_error("Error: Unknown operator");
	}
}

