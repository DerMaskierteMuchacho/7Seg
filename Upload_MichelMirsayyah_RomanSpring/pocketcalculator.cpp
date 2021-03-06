#include "pocketcalculator.h"
#include "../Calculator7Lib/sevensegment.h"
#include "../Calculator7Lib/calc.h"

#include <iostream>
#include <string>
#include <exception>
#include <queue>
#include <regex>

bool const __DEBUG = false;

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
				outStream << asciiGenerator.numberStringToAsciiString(calculator.roundToPercision2(result));
				outStream << "\n";
			}
		}
		catch (InvalidInputException &) {
			outStream << asciiGenerator.getErrorString();
		}
		catch (InvalidStringException &) {
			outStream << asciiGenerator.getErrorString();
		}
		catch (InvalidCalculationException &) {
			outStream << asciiGenerator.getErrorString();
		}
	} while (isRunning);
}