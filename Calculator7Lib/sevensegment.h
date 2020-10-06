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
	std::string createStringFromArray(std::vector<std::vector<std::string>>) const;
public:
	std::string numberStringToAsciiString(std::string) const;
	std::string getErrorString() const;
};