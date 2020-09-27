// Calculator7Seg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <exception>
#include <queue>
#include <regex>
#include "../Calculator7Lib/AsciiGenerator.h"
#include "../Calculator7Lib/Calculator.h"
#include "../Calculator7Lib/Calculator.cpp"

bool const __DEBUG = true;

struct InvalidInputException : public std::exception {
	const char* what() const throw ()
	{
		return "Invalid input!";
	}
};

bool inputToData(CalcData& inData, std::istream& inStream) {
	std::string inputStr{};
	std::getline(inStream, inputStr);
	if (inputStr.compare("exit") == 0)
	{
		return false;
	}
	std::regex basic_regex("([-]?([0-9]*[.,])?[0-9]+)[ ]*([\\+\\*\\/\\-\\%])[ ]*([-]?([0-9]*[.,])?[0-9]+)");
	std::smatch regexMatching;
	bool match = std::regex_search(inputStr, regexMatching, basic_regex);

	if (__DEBUG)
	{
		std::cout << "Group 1: " + regexMatching.str(0) + "\n";
		std::cout << "Group 2: " + regexMatching.str(1) + "\n";
		std::cout << "Group 3: " + regexMatching.str(2) + "\n";
		std::cout << "Group 4: " + regexMatching.str(3) + "\n";
		std::cout << "Group 5: " + regexMatching.str(4) + "\n";
		std::cout << "Group 6: " + regexMatching.str(5) + "\n";
	}
	if (!match) {
		throw InvalidInputException();
	}

	inData.number.push(std::stod(regexMatching.str(1)));
	inData.number.push(std::stod(regexMatching.str(4)));
	inData.operation.push(regexMatching.str(3)[0]);

	return true;
}

void pocketcalculator(std::istream& inStream, std::ostream& outStream) {
	bool isRunning = true;
	do {
		AsciiGenerator asciiGenerator;
		outStream << "Please enter a calculation(+ - * / %)\nType 'exit' to abort\n";
		try {
			Calculator calculator;
			CalcData inData;
			isRunning = inputToData(inData, inStream);
			if (isRunning) {
				double result = calculator.calc(inData);
				outStream << "Result: \n";
				outStream << asciiGenerator.intToAsciiString(calculator.limitTo8(result));
				outStream << "\n";
			}
		}
		catch (InvalidInputException& e) {
			outStream << asciiGenerator.getErrorString();
			//isRunning = false;
		}
		catch (InvalidCalculationException& e) {
			outStream << asciiGenerator.getErrorString();
			//isRunning = false;
		}
	} while (isRunning);
}

int main()
{
	pocketcalculator(std::cin, std::cout);
}