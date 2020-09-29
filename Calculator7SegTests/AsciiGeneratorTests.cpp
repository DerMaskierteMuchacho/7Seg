#include "pch.h"
#include "CppUnitTest.h"
#include "../Calculator7Lib/AsciiGenerator.h"
#include <queue>
#include <sstream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Calculator7SegTests
{
	TEST_CLASS(AsciiGeneratorTests)
	{
	public:

		TEST_METHOD(IntegerOutputTest)
		{
			AsciiGenerator generator;
			auto result = generator.intToAsciiString("8");
			Assert::AreEqual(0, result.compare(" --   \n|  |  \n --   \n|  |  \n --   \n"));
		}

		TEST_METHOD(DoubleOutputTest)
		{
			AsciiGenerator generator;
			Assert::AreEqual(0, generator.intToAsciiString("8.5").compare(" --          --   \n|  |        |     \n --          --   \n|  |     |     |  \n --          --   \n"));
			Assert::AreEqual(0, generator.intToAsciiString("8,5").compare(" --          --   \n|  |        |     \n --          --   \n|  |     |     |  \n --          --   \n"));
		}

		TEST_METHOD(BigNumberTest)
		{
			AsciiGenerator generator;
			auto result = generator.intToAsciiString("12345.67890");

			Assert::AreEqual(0, generator.intToAsciiString("12345.67890").compare("       --    --          --          --    --    --    --    --   \n   |     |     |  |  |  |           |        |  |  |  |  |  |  |  \n       --    --    --    --          --          --    --         \n   |  |        |     |     |     |  |  |     |  |  |     |  |  |  \n       --    --          --          --          --    --    --   \n"));

			/*
			"       --    --          --          --    --    --    --    --   "
			"   |     |     |  |  |  |           |        |  |  |  |  |  |  |  "
			"       --    --    --    --          --          --    --         "
			"   |  |        |     |     |     |  |  |     |  |  |     |  |  |  "
			"       --    --          --          --          --    --    --   "
			*/
		}

		TEST_METHOD(NegativeNumberTest)
		{
			AsciiGenerator generator;
			auto result = generator.intToAsciiString("-123");

			Assert::AreEqual(0, generator.intToAsciiString("-123").compare("             --    --   \n         |     |     |  \n --          --    --   \n         |  |        |  \n             --    --   \n"));
		}

		TEST_METHOD(DigitTest)
		{
			AsciiGenerator generator;
			Assert::AreEqual(0, generator.intToAsciiString("-").compare("      \n      \n --   \n      \n      \n"));
			Assert::AreEqual(0, generator.intToAsciiString("0").compare(" --   \n|  |  \n      \n|  |  \n --   \n"));
			Assert::AreEqual(0, generator.intToAsciiString("1").compare("      \n   |  \n      \n   |  \n      \n"));
			Assert::AreEqual(0, generator.intToAsciiString("2").compare(" --   \n   |  \n --   \n|     \n --   \n"));
			Assert::AreEqual(0, generator.intToAsciiString("3").compare(" --   \n   |  \n --   \n   |  \n --   \n"));
			Assert::AreEqual(0, generator.intToAsciiString("4").compare("      \n|  |  \n --   \n   |  \n      \n"));
			Assert::AreEqual(0, generator.intToAsciiString("5").compare(" --   \n|     \n --   \n   |  \n --   \n"));
			Assert::AreEqual(0, generator.intToAsciiString("6").compare(" --   \n|     \n --   \n|  |  \n --   \n"));
			Assert::AreEqual(0, generator.intToAsciiString("7").compare(" --   \n   |  \n      \n   |  \n      \n"));
			Assert::AreEqual(0, generator.intToAsciiString("8").compare(" --   \n|  |  \n --   \n|  |  \n --   \n"));
			Assert::AreEqual(0, generator.intToAsciiString("9").compare(" --   \n|  |  \n --   \n   |  \n --   \n"));
		}
	};
}