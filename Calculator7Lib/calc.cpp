#include "calc.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <queue>

double Calculator::giveFrontAndPop(std::queue<double>& number) const {
	double n = number.front();
	number.pop();
	return n;
}
double Calculator::calc(struct CalcData& data) const {
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

std::string Calculator::roundToPercision2(double const number) const {
	std::ostringstream oStrStream;
	oStrStream << std::fixed << std::setprecision(2) << number;
	std::string numberString = oStrStream.str();
	if (*std::rbegin(numberString) == '0') {
		numberString.erase(numberString.end() - 1);
		if (*std::rbegin(numberString) == '0') {
			numberString.erase(numberString.end() - 1);
			if (*std::rbegin(numberString) == '.')
				numberString.erase(numberString.end() - 1);
		}
	}
	return numberString;
}