#include <queue>
#include "Calculator.h"
#include <string>
#include <iostream>

int Calculator::giveFrontAndPop(std::queue<double>& number) {
	int n = number.front();
	number.pop();
	return n;
}
double Calculator::calc(std::queue<double>& number, std::queue<char>& operation) {
	if (operation.size() < 1)
		throw InvalidCalculationException();
	if (number.size() == operation.size() - 1)
		throw InvalidCalculationException();
	double result = giveFrontAndPop(number);
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
		case '%':
			if (number.front() == 0) throw InvalidCalculationException();
			result = (int)result % giveFrontAndPop(number);
			break;
		default:
			throw InvalidCalculationException();
		}
		operation.pop();
	}
	return result;
}

std::string Calculator::limitTo8(double const number) {
	std::string numberString = std::to_string(number);
	return numberString.substr(0, (number>0)?8:9);
}