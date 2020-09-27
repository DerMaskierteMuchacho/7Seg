#include <queue>
#include "Calculator.h"
#include <string>

double Calculator::giveFrontAndPop(std::queue<double>& number) {
	double n = number.front();
	number.pop();
	return n;
}
double Calculator::calc(struct CalcData& data) {
	if (data.operation.size() < 1)
		throw InvalidCalculationException();
	if (data.number.size() == data.operation.size() - 1)
		throw InvalidCalculationException();
	double result = giveFrontAndPop(data.number);
	while (!data.operation.empty()) {
		switch (data.operation.front()) {
		case '+':
			result += giveFrontAndPop(data.number);
			break;
		case '-':
			result -= giveFrontAndPop(data.number);
			break;
		case '*':
			result *= giveFrontAndPop(data.number);
			break;
		case '/':
			if (data.number.front() == 0) throw InvalidCalculationException();
			result /= giveFrontAndPop(data.number);
			break;
		case '%':
			if (data.number.front() == 0) throw InvalidCalculationException();
			result = (int)result % (int)giveFrontAndPop(data.number);
			break;
		default:
			throw InvalidCalculationException();
		}
		data.operation.pop();
	}
	return result;
}

std::string Calculator::limitTo8(double const number) {
	std::string numberString = std::to_string(number);
	return numberString.substr(0, (number > 0) ? 8 : 9);
}