#pragma once
#include <iosfwd>
#include <exception>
#include <queue>

struct InvalidCalculationException : public std::exception {
	const char* what() const throw ()
	{
		return "Invalid calculation!";
	}
};

class Calculator
{
private:
	int result;
	int giveFrontAndPop(std::queue<int> &);

public:
	void calc(std::queue<int> &, std::queue<char> &);
	int getResult();
};
