#include <queue>
#include "Calculator.h"
int Calculator::giveFrontAndPop(std::queue<int>& number) {
	int n = number.front();
	number.pop();
	return n;
}
void Calculator::calc(std::queue<int>& number, std::queue<char>& operation) {
	if (operation.size() < 1)
		throw InvalidCalculationException();
	if (number.size() == operation.size() - 1)
		throw InvalidCalculationException();
	result = giveFrontAndPop(number);
	while (!operation.empty()) {
		switch (operation.front()) {
		case '+':
			result += giveFrontAndPop(number);
			break;
		case '-':
			result -= giveFrontAndPop(number);
			break;
		case '*':
			result *= giveFrontAndPop(number);
			break;
		case '/':
			if (number.front() == 0) throw InvalidCalculationException();
			result /= giveFrontAndPop(number);
			break;
		default:
			throw InvalidCalculationException();
		}
		operation.pop();
	}
}

double Calculator::getResult() {
	return result;
}