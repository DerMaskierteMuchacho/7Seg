// Calculator7Seg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <exception>
#include <queue>
#include "Calculator.h"
#include "AsciiGenerator.h"

struct InputData {
	std::queue<int> number;
	std::queue<char> operation;
};
struct InvalidInputException : public std::exception {
	const char* what() const throw ()
	{
		return "Invalid input!";
	}
};

bool inputToData(InputData& inData, std::istream& inStream) {
	std::string in;
	std::string temp = "";
	std::getline(inStream, in);
	in.erase(std::remove_if(in.begin(), in.end(), isspace), in.end());
	if (!in.compare("exit")) {
		return false;
	}
	else {
		size_t size = in.length();
		if (size >= 3) {
			for (int i = 0; i < size; i++) {
				if (std::isdigit(in[i])) {
					temp += in[i];
				}
				else {
					if (temp.length() > 0) {
						inData.number.push(std::stoi(temp));
						temp = "";
					}
					else
						throw InvalidInputException();
					if (in[i] == '+' || in[i] == '-' || in[i] == '*' || in[i] == '/') {
						inData.operation.push(in[i]);
					}

					else
						throw InvalidInputException();
				}
			}
			if (temp.length() > 0)
				inData.number.push(std::stoi(temp));
			return true;
		}
		throw InvalidInputException();
	}
}

void pocketcalculator(std::istream& inStream, std::ostream& outStream) {
	AsciiGenerator asciiGenerator;

	bool isRunning = true;
	do {
		outStream << "Please enter a calculation(+ - * /)\nType 'exit' to abort\n";
		try {
			Calculator calculator;
			InputData inData;
			isRunning = inputToData(inData, inStream);
			calculator.calc(inData.number, inData.operation);
			outStream << "Result: \n";
			//ToDo: Limit to 8-char
			outStream << asciiGenerator.intToAsciiString(calculator.getResult());
			//ToDo: Cute in VS
			outStream << "\n";
		}
		catch (InvalidInputException& e) {
			outStream << e.what();
			isRunning = false;
		}
		catch (InvalidCalculationException& e) {
			outStream << e.what();
			isRunning = false;
		}
	} while (isRunning);
}

int main()
{
	pocketcalculator(std::cin, std::cout);
}