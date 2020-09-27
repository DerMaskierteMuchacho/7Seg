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
		/*
		TEST_METHOD(DivisionByZeroTest)
		{
			Calculator calculator;
			std::queue<int> operands;
			operands.push(5);
			operands.push(0);
			std::queue<char> operators;
			operators.push('/');

			//void (*calculator.calc)(int);
			//foo = &my_int_func;

			Assert::ExpectException<InvalidCalculationException>(calculator.calc(operands, operators));
		}*/

		TEST_METHOD(AdditionTest)
		{
			Calculator calculator;
			std::queue<double> operands;
			operands.push(5);
			operands.push(3);
			std::queue<char> operators;
			operators.push('+');

			Assert::AreEqual(8.0, calculator.calc(operands, operators));
		}

		TEST_METHOD(ModuloTest)
		{
			Calculator calculator;
			std::queue<double> operands;
			operands.push(5);
			operands.push(3);
			std::queue<char> operators;
			operators.push('%');

			Assert::AreEqual(2.0, calculator.calc(operands, operators));
		}
	};
}