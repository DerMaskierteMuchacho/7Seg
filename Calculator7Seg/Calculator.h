#pragma once
#include <iosfwd>

class Calculator
{
private:
	calcInput getInput(std::istream&);
	int calc(int, int, char);
	void printResult(int);

public:
	int run()
};
