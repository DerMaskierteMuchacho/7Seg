#pragma once
#include <string>
#include <vector>
class AsciiGenerator {
private:
	std::string createStringFromArray(std::vector<std::vector<std::string>>);
public:
	std::string intToAsciiString(std::string);
	std::string getErrorString();
};