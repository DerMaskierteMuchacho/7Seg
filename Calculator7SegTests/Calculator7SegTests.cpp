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
			InputData inData;
			inData.number.push(5);
			inData.number.push(0);
			inData.operation.push('/');

			auto func = [] { calculator.calc(inData.number, inData.operation); };
			Assert::ExpectException<InvalidCalculationException>(func);
		}*/

		TEST_METHOD(AdditionTest)
		{
			Calculator calculator;
			std::queue<int> hans;
			hans.push(5);
			hans.push(3);
			std::queue<char> ueli;
			ueli.push('+');
			calculator.calc(hans, ueli);

			Assert::AreEqual(8.0, (double)calculator.getResult());
		}
	};
}