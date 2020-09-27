#pragma once
#include <iosfwd>
#include <exception>
#include <queue>
#include <string>

struct InvalidCalculationException : public std::exception {
	const char* what() const throw ()
	{
		return "Invalid calculation!";
	}
};

class Calculator
{
private:
	int giveFrontAndPop(std::queue<double>&);

public:
	double calc(std::queue<double>&, std::queue<char>&);
	std::string limitTo8(double const);
};
