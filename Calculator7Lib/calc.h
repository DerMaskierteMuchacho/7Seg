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
	double giveFrontAndPop(std::queue<double>&);

public:
	double calc(struct CalcData&);
	std::string limitTo8(double const);
};
