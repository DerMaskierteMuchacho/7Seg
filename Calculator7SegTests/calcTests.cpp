#include "pch.h"
#include "CppUnitTest.h"
#include "../Calculator7Lib/calc.h"
#include <queue>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Calculator7SegTests
{
	TEST_CLASS(CalculatorTests)
	{
	public:

		TEST_METHOD(DivisionByZeroTest)
		{
			Calculator calculator;
			CalcData data;
			data.number.push(5);
			data.number.push(0);
			data.operation.push('/');

			try {
				calculator.calc(data);
				Assert::Fail();
			}
			catch (InvalidCalculationException&) {
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::IsTrue(true);
			}

			//does not work
			//Assert::ExpectException<InvalidCalculationException>(calculator.calc(data));
		}

		TEST_METHOD(AdditionTest)
		{
			Calculator calculator;
			CalcData data;
			data.number.push(5);
			data.number.push(3);
			data.operation.push('+');

			Assert::AreEqual(8.0, calculator.calc(data));
		}

		TEST_METHOD(AdditionDoubleTest)
		{
			Calculator calculator;
			CalcData data;
			data.number.push(5.5);
			data.number.push(4.5);
			data.operation.push('+');

			Assert::AreEqual(10.0, calculator.calc(data));
		}

		TEST_METHOD(SubtractionTest)
		{
			Calculator calculator;
			CalcData data;
			data.number.push(5);
			data.number.push(3);
			data.operation.push('-');

			Assert::AreEqual(2.0, calculator.calc(data));
		}

		TEST_METHOD(MultiplicationTest)
		{
			Calculator calculator;
			CalcData data;
			data.number.push(5);
			data.number.push(3);
			data.operation.push('*');

			Assert::AreEqual(15.0, calculator.calc(data));
		}

		TEST_METHOD(DivisionTest)
		{
			Calculator calculator;
			CalcData data;
			data.number.push(6);
			data.number.push(3);
			data.operation.push('/');

			Assert::AreEqual(2.0, calculator.calc(data));
		}
		TEST_METHOD(ModuloTest)
		{
			Calculator calculator;
			CalcData data;
			data.number.push(5);
			data.number.push(3);
			data.operation.push('%');

			Assert::AreEqual(2.0, calculator.calc(data));
		}

		
		TEST_METHOD(FloatNumber)
		{
			using namespace std::literals;
			Calculator calculator;
			Assert::AreEqual("99.45"s, calculator.roundToPercision2(99.454534545));
		}
		TEST_METHOD(NegativeDouble)
		{
			using namespace std::literals;
			Calculator calculator;
			Assert::AreEqual("-99.45"s, calculator.roundToPercision2(-99.454534545));
		}
	};
}