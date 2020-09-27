#include <queue>
#include "Calculator.h"
#include <string>
#include <sstream>
#include <iomanip>

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
	/*std::ostringstream outStrStream;
	outStrStream.setf(std::ios::fixed);
	outStrStream << std::setprecision(0) << number;
	int length = outStrStream.str().length();

	std::ostringstream outStrStream2;
	outStrStream2.setf(std::ios::fixed);
	outStrStream2 << std::setprecision((length <= 8) ? 8 - length : 0) << number;
	return outStrStream2.str().substr(0, 8);*/

	//std::string numberString = std::to_string(number);

	return std::to_string(number).substr(0, 8);
}