/*	Testat 1 for Modul C++
*	Michel Mirsayyah und Roman Spring
*/

#pragma once
#include "calc.h"
#include <iosfwd>
struct InvalidInputException : public std::exception {
	const char* what() const throw ()
	{
		return "Invalid input!";
	}
};
void pocketcalculator(std::istream&, std::ostream&);
bool inputToData(CalcData&, std::istream&);