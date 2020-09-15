#include "Calculator.h"

void Calculator::calc(int a, int b, char operation) {
	switch (operation) {
	case '+':
		this->result = a + b;
		break;
	case '-':
		this->result = a - b;
		break;
	case '*':
		this->result = a * b;
		break;
	case '/':
		this->result = a / b;
		break;
	}
}

int Calculator::getResult() {
	return this->result;
}