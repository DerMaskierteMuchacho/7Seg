#include "Calculation.h"

int Calculator::calc(int a, int b, char operation)
{
	switch (operation)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	}
}