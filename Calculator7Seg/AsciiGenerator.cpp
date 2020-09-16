#include "AsciiGenerator.h"
#include <string>
#include <vector>

std::string createStringFromArray(std::vector<std::vector<std::string>> array)
{
	std::string output;
	std::string spaceBetweenDigits = "  ";
	for (int i = 0; i < 5; i++)
	{
		for (std::vector<std::string> level : array)
		{
			output += level[i] + spaceBetweenDigits;
			if (i != 1 && i != 3)
			{
				output += " ";
			}
		}
		output += "\n";
	}

	return output;
}

std::string AsciiGenerator::intToAsciiString(int input)
{
	std::vector<std::vector<std::string>> output;
	std::string inputAsString = std::to_string(input);

	for (char digit : inputAsString)
	{
		switch (digit)
		{
		case '0':
			output.push_back({ " --", "|  |", "   ", "|  |", " --" });
			break;
		case '1':
			output.push_back({ "   ", "   |", "   ", "   |", "   " });
			break;
		case '2':
			output.push_back({ " --", "   |", " --", "|   ", " --" });
			break;
		case '3':
			output.push_back({ " --", "   |", " --", "   |", " --" });
			break;
		case '4':
			output.push_back({ "   ", "|  |", " --", "   |", "   " });
			break;
		case '5':
			output.push_back({ " --", "|   ", " --", "   |", " --" });
			break;
		case '6':
			output.push_back({ " --", "|   ", " --", "|  |", " --" });
			break;
		case '7':
			output.push_back({ " --", "   |", "   ", "   |", "   " });
			break;
		case '8':
			output.push_back({ " --", "|  |", " --", "|  |", " --" });
			break;
		case '9':
			output.push_back({ " --", "|  |", " --", "   |", " --" });
			break;
		}
	}

	return createStringFromArray(output);
}