#pragma once
#include <string>
#include <vector>
class AsciiGenerator {
private:
	std::string createStringFromArray(std::vector<std::vector<std::string>>);
public:
	std::string intToAsciiString(double);
	std::string getErrorString();
};