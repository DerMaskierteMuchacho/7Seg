#pragma once
#include <iosfwd>

class Calculator
{
private:
	int result;

public:
	void calc(int, int, char);
	int getResult();
};
