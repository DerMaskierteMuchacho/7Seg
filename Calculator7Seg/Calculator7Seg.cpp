// Calculator7Seg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <exception>
#include <queue>
#include "../Calculator7Lib/AsciiGenerator.h"
#include "../Calculator7Lib/Calculator.h"

struct InputData {
	std::queue<int> number{};
	std::queue<char> operation{};
};
struct InvalidInputException : public std::exception {
	const char* what() const throw ()
	{
		return "Invalid input!";
	}
};

bool inputToData(InputData& inData, std::istream& inStream) {
	std::string inputStr{};
	std::string temp{ "" };
	std::getline(inStream, inputStr);
	inputStr.erase(std::remove_if(inputStr.begin(), inputStr.end(), isspace), inputStr.end());
	if (inputStr.compare("exit")==0) { //TODO compare
		return false;
	}
	else {
		size_t size = inputStr.length();
		if (size >= 3) {
			for (auto charFromInputStr : inputStr) {
				if (std::isdigit(charFromInputStr)) {
					temp += charFromInputStr;
				}
				else {
					if (temp.length() > 0) {
						inData.number.push(std::stoi(temp));
						temp = "";
					}
					else
						throw InvalidInputException();
					if (charFromInputStr == '+' || 
						charFromInputStr == '-' || 
						charFromInputStr == '*' || 
						charFromInputStr == '/' || 
						charFromInputStr == '^' ||
						charFromInputStr == '%') {
						inData.operation.push(charFromInputStr);
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
	bool isRunning = true;
	do {
		AsciiGenerator asciiGenerator;
		outStream << "Please enter a calculation(+ - * / %)\nType 'exit' to abort\n";
		try {
			Calculator calculator;
			InputData inData;
			isRunning = inputToData(inData, inStream);
			double result = calculator.calc(inData.number, inData.operation);
			outStream << "Result: \n";
			//ToDo: Limit to 8-char
			outStream << asciiGenerator.intToAsciiString(result);
			//ToDo: Cute in VS
			outStream << "\n";
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