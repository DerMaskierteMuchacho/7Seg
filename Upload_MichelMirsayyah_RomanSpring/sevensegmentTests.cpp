/*	Testat 1 for Modul C++
*	Michel Mirsayyah und Roman Spring
*/

#include "pch.h"
#include "CppUnitTest.h"
#include "../Calculator7Lib/sevensegment.h"
#include <queue>
#include <sstream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace pocketcalculatorTests
{
	TEST_CLASS(AsciiGeneratorTests)
	{
	public:

		TEST_METHOD(IntegerOutputTest)
		{
			AsciiGenerator generator;
			Assert::AreEqual(0, generator.numberStringToAsciiString("8").compare(" --   \n|  |  \n --   \n|  |  \n --   \n"));
		}

		TEST_METHOD(DoubleOutputTest)
		{
			AsciiGenerator generator;
			Assert::AreEqual(0, generator.numberStringToAsciiString("8.5").compare(" --          --   \n|  |        |     \n --          --   \n|  |     |     |  \n --          --   \n"));
			Assert::AreEqual(0, generator.numberStringToAsciiString("8,5").compare(" --          --   \n|  |        |     \n --          --   \n|  |     |     |  \n --          --   \n"));
		}

		TEST_METHOD(BigInputTest)
		{
			AsciiGenerator generator;
			try
			{
				auto result = generator.numberStringToAsciiString("123456.89");
				Assert::Fail();
			}
			catch (InvalidStringException &)
			{
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::IsTrue(false);
			}
		}

		TEST_METHOD(NegativeNumberTest)
		{
			AsciiGenerator generator;
			auto result = generator.numberStringToAsciiString("-123");

			Assert::AreEqual(0, generator.numberStringToAsciiString("-123").compare("             --    --   \n         |     |     |  \n --          --    --   \n         |  |        |  \n             --    --   \n"));
		}

		TEST_METHOD(DigitTest)
		{
			AsciiGenerator generator;
			Assert::AreEqual(0, generator.numberStringToAsciiString("-").compare("      \n      \n --   \n      \n      \n"));
			Assert::AreEqual(0, generator.numberStringToAsciiString("0").compare(" --   \n|  |  \n      \n|  |  \n --   \n"));
			Assert::AreEqual(0, generator.numberStringToAsciiString("1").compare("      \n   |  \n      \n   |  \n      \n"));
			Assert::AreEqual(0, generator.numberStringToAsciiString("2").compare(" --   \n   |  \n --   \n|     \n --   \n"));
			Assert::AreEqual(0, generator.numberStringToAsciiString("3").compare(" --   \n   |  \n --   \n   |  \n --   \n"));
			Assert::AreEqual(0, generator.numberStringToAsciiString("4").compare("      \n|  |  \n --   \n   |  \n      \n"));
			Assert::AreEqual(0, generator.numberStringToAsciiString("5").compare(" --   \n|     \n --   \n   |  \n --   \n"));
			Assert::AreEqual(0, generator.numberStringToAsciiString("6").compare(" --   \n|     \n --   \n|  |  \n --   \n"));
			Assert::AreEqual(0, generator.numberStringToAsciiString("7").compare(" --   \n   |  \n      \n   |  \n      \n"));
			Assert::AreEqual(0, generator.numberStringToAsciiString("8").compare(" --   \n|  |  \n --   \n|  |  \n --   \n"));
			Assert::AreEqual(0, generator.numberStringToAsciiString("9").compare(" --   \n|  |  \n --   \n   |  \n --   \n"));
		}

		TEST_METHOD(ErrorStringTest)
		{
			AsciiGenerator generator;
			auto a = generator.getErrorString();
			Assert::AreEqual(0, generator.getErrorString().compare(" --                           \n|                             \n --    --    --    --    --   \n|     |     |     |  |  |     \n --                --         \n"));
		}

		TEST_METHOD(ExceptionTest)
		{
			AsciiGenerator generator;
			try
			{
				auto result = generator.numberStringToAsciiString("ASDF");
				Assert::Fail();
			}
			catch (InvalidStringException &)
			{
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::IsTrue(false);
			}
		}
	};
}