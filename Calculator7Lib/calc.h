#pragma once
#include <iosfwd>
#include <exception>
#include <queue>
#include <string>
struct CalcData {
	std::queue<double> number{};
	std::queue<char> operation{};
};

struct InvalidCalculationException : public std::exception {
	const char* what() const throw ()
	{
		return "Invalid calculation!";
	}
};

class Calculator
{
private:
	double giveFrontAndPop(std::queue<double>&) const;

public:
	double calc(struct CalcData&) const;
	std::string roundToPercision2(double const) const;
};
