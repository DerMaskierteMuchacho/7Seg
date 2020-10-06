#include "pch.h"
#include "CppUnitTest.h"
#include "../Calculator7Lib/pocketcalculator.h"
#include "../Calculator7Lib/calc.h"
#include <queue>
#include <sstream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Calculator7SegTests
{
	TEST_CLASS(Calculator7SegTests)
	{
	private:
		bool compareDatastruct(struct CalcData d1, struct CalcData d2) {
			while (!d1.number.empty()) {
				double n1 = d1.number.front();
				if (!(n1 == d2.number.front())) return false;
				d1.number.pop();
				d2.number.pop();
			}
			if (d2.number.size() != 0) return false;
			while (!d1.operation.empty()) {
				char c1 = d1.operation.front();
				if (!(c1 == d2.operation.front())) return false;
				d1.operation.pop();
				d2.operation.pop();
			}
			if (d2.operation.size() != 0) return false;
			return true;
		}
	public:

		TEST_METHOD(inputToData_addition)
		{
			struct CalcData data {};
			struct CalcData testData {};
			testData.number.push(5);
			testData.number.push(5);
			testData.operation.push('+');
			std::istringstream input{ "5+5" };

			inputToData(data, input);
			Assert::IsTrue(compareDatastruct(data, testData));
		}

		TEST_METHOD(inputToData_subtraction)
		{
			struct CalcData data {};
			struct CalcData testData {};
			testData.number.push(5);
			testData.number.push(5);
			testData.operation.push('-');
			std::istringstream input{ "5-5" };

			inputToData(data, input);
			Assert::IsTrue(compareDatastruct(data, testData));
		}

		TEST_METHOD(inputToData_muliplication)
		{
			struct CalcData data {};
			struct CalcData testData {};
			testData.number.push(5);
			testData.number.push(5);
			testData.operation.push('*');
			std::istringstream input{ "5*5" };

			inputToData(data, input);
			Assert::IsTrue(compareDatastruct(data, testData));
		}

		TEST_METHOD(inputToData_division)
		{
			struct CalcData data {};
			struct CalcData testData {};
			testData.number.push(5);
			testData.number.push(5);
			testData.operation.push('/');
			std::istringstream input{ "5/5" };

			inputToData(data, input);
			Assert::IsTrue(compareDatastruct(data, testData));
		}

		TEST_METHOD(inputToData_modulo)
		{
			struct CalcData data {};
			struct CalcData testData {};
			testData.number.push(5);
			testData.number.push(5);
			testData.operation.push('+');
			std::istringstream input{ "5+5" };

			inputToData(data, input);
			Assert::IsTrue(compareDatastruct(data, testData));
		}

		TEST_METHOD(inputToData_floatingPoint)
		{
			struct CalcData data {};
			struct CalcData testData {};
			testData.number.push(5.555);
			testData.number.push(5.55);
			testData.operation.push('+');
			std::istringstream input{ "5.555+5.55" };

			inputToData(data, input);
			Assert::IsTrue(compareDatastruct(data, testData));
		}

		TEST_METHOD(inputToData_whiteSpaces)
		{
			struct CalcData data {};
			struct CalcData testData {};
			testData.number.push(5);
			testData.number.push(5);
			testData.operation.push('+');
			std::istringstream input{ "     5          +     5         " };

			inputToData(data, input);
			Assert::IsTrue(compareDatastruct(data, testData));
		}

		TEST_METHOD(inputToData_returnCorrectInput)
		{
			struct CalcData data {};
			std::istringstream input{ "5+5" };
			Assert::IsTrue(inputToData(data, input));
		}

		TEST_METHOD(inputToData_returnExit)
		{
			struct CalcData data {};
			std::istringstream input{ "exit" };
			Assert::IsFalse(inputToData(data, input));
		}
		TEST_METHOD(inputToData_exception)
		{
			struct CalcData data {};
			std::istringstream input{ "Hello World!!!" };
			try {
				inputToData(data, input);
				Assert::Fail();
			}
			catch (InvalidInputException&) {
				Assert::IsTrue(true);
			}
			//does not work
			//Assert::ExpectException<InvalidInputException>(inputToData(data, input));
		}
	};
}