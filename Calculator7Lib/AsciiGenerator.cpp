#include "AsciiGenerator.h"
#include <string>
#include <vector>

std::string const empty = "    ";
std::string const line = " -- ";
std::string const bar = "|  |";
std::string const barLeft = "|   ";
std::string const barRight = "   |";
std::string const spaceBetweenDigits = "  ";

std::string AsciiGenerator::createStringFromArray(std::vector<std::vector<std::string>> array)
{
	std::string output;

	for (int i = 0; i < 5; i++)
	{
		for (std::vector<std::string> level : array)
		{
			output += level[i] + spaceBetweenDigits;
		}
		output += "\n";
	}

	return output;
}

std::string AsciiGenerator::intToAsciiString(double input)
{
	std::vector<std::vector<std::string>> output; //list<string[]>
	std::string inputAsString = std::to_string(input);

	for (char digit : inputAsString)
	{
		switch (digit)
		{
		case '.':
		case ',':
			output.push_back({ empty, empty, empty, barRight, empty });
			break;
		case '-':
			output.push_back({ empty, empty, line, empty, empty });
			break;
		case '0':
			output.push_back({ line, bar, empty, bar, line });
			break;
		case '1':
			output.push_back({ empty, barRight, empty, barRight, empty });
			break;
		case '2':
			output.push_back({ line, barRight, line, barLeft, line });
			break;
		case '3':
			output.push_back({ line, barRight, line, barRight, line });
			break;
		case '4':
			output.push_back({ empty, bar, line, barRight, empty });
			break;
		case '5':
			output.push_back({ line, barLeft, line, barRight, line });
			break;
		case '6':
			output.push_back({ line, barLeft, line, bar, line });
			break;
		case '7':
			output.push_back({ line, barRight, empty, barRight, empty });
			break;
		case '8':
			output.push_back({ line, bar, line, bar, line });
			break;
		case '9':
			output.push_back({ line, bar, line, barRight, line });
			break;
		}
	}

	return createStringFromArray(output);
}

std::string AsciiGenerator::getErrorString()
{
	std::vector<std::string> e{ line, barLeft, line, barLeft, line };
	std::vector<std::string> r{ line, bar,line, bar, empty };
	std::vector<std::string> o{ line, bar, empty, bar, line };
	std::vector<std::vector<std::string>> output{ e,r,r,o,r };

	return createStringFromArray(output);
}