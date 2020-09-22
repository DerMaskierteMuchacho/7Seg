#include "pch.h"
#include "CppUnitTest.h"
#include "../Calculator7Lib/Calculator.h"
#include <queue>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Calculator7SegTests
{
	TEST_CLASS(Calculator7SegTests)
	{
	public:

		/*TEST_METHOD(DivisionByZeroTest)
		{
			Calculator calculator;
			std::queue<int> hans;
			hans.push(5);
			hans.push(0);
			std::queue<char> ueli;
			ueli.push('/');

			Assert::ExpectException<InvalidCalculationException>(calculator.calc(hans, ueli));
		}*/

		TEST_METHOD(AdditionTest)
		{
			Calculator calculator;
			std::queue<int> hans;
			hans.push(5);
			hans.push(3);
			std::queue<char> ueli;
			ueli.push('+');

			Assert::AreEqual(8.0, calculator.calc(hans, ueli));
		}

		TEST_METHOD(ModuloTest)
		{
			Calculator calculator;
			std::queue<int> hans;
			hans.push(5);
			hans.push(3);
			std::queue<char> ueli;
			ueli.push('%');

			Assert::AreEqual(2.0, calculator.calc(hans, ueli));
		}
	};
}