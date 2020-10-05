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
			catch (InvalidCalculationException& e) {
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

		TEST_METHOD(LimitLong)
		{
			Calculator calculator;
			Assert::AreEqual(8, (int)calculator.limitTo8(9999999999).length());
		}
		TEST_METHOD(LimitShort)
		{
			Calculator calculator;
			Assert::AreEqual(8, (int)calculator.limitTo8(880).length());
		}
		TEST_METHOD(LimitFloat)
		{
			Calculator calculator;
			Assert::AreEqual(8, (int)calculator.limitTo8(99.454534545).length());
		}
		TEST_METHOD(LimitNegativeDouble)
		{
			Calculator calculator;
			Assert::AreEqual(8, (int)calculator.limitTo8(-99.454534545).length());
		}
	};
}