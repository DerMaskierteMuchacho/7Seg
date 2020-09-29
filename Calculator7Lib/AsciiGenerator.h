#pragma once
#include <string>
#include <vector>

struct InvalidStringException : public std::exception {
	const char* what() const throw ()
	{
		return "Invalid input string!\nOnly numbers can be converted";
	}
};

class AsciiGenerator {
private:
	std::string createStringFromArray(std::vector<std::vector<std::string>>);
public:
	std::string intToAsciiString(std::string);
	std::string getErrorString();
};