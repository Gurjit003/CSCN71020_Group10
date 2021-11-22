#include "pch.h"
#include "CppUnitTest.h"

extern "C" char* analyzeRectangle(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace rectangletest
{
	TEST_CLASS(rectangletest)
	{
	public:
		
		TEST_METHOD(testcorrectrectangle) //testing that all the users inputs are correct 
		{
			int x1 = 3;
			int y1 = 1;
			int x2 = 3;
			int y2 = 6;
			int x3 = 6;
			int y3 = 6;
			int x4 = 6;
			int y4 = 1;
			char* expected = "it forms a rectangle.\n";

			char* result = analyzeRectangle(x1, x2, x3, x4, y1, y2, y3, y4);

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Testfory1inputequallingy2) //testing that the code will recognize that that user input their first and second y input to be the same
		{
			int x1 = 3;
			int y1 = 1;
			int x2 = 3;
			int y2 = 1;
			int x3 = 6;
			int y3 = 6;
			int x4 = 6;
			int y4 = 1;
			char* expected = "4 points do not form a rectangle. Try again!\n";

			char* result = analyzeRectangle(x1, x2, x3, x4, y1, y2, y3, y4);

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Testy1andy3areequal) //testing the system recognozes the user input y1 and y3 to be the same
		{
			int x1 = 3;
			int y1 = 1;
			int x2 = 3;
			int y2 = 6;
			int x3 = 6;
			int y3 = 1;
			int x4 = 6;
			int y4 = 1;
			char* expected = "4 points do not form a rectangle. Try again!\n";

			char* result = analyzeRectangle(x1, x2, x3, x4, y1, y2, y3, y4);

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Testx1andx4areequal) //the system recognizes that x1 and x4 are equal 
		{
			int x1 = 3;
			int y1 = 1;
			int x2 = 3;
			int y2 = 6;
			int x3 = 6;
			int y3 = 6;
			int x4 = 3;
			int y4 = 1;
			char* expected = "4 points do not form a rectangle. Try again!\n";

			char* result = analyzeRectangle(x1, x2, x3, x4, y1, y2, y3, y4);

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Testx1andx3arethesame) //testing that the system recognozes x1 and x3 are the same
		{
			int x1 = 3;
			int y1 = 1;
			int x2 = 3;
			int y2 = 6;
			int x3 = 3;
			int y3 = 6;
			int x4 = 6;
			int y4 = 1;
			char* expected = "4 points do not form a rectangle. Try again!\n";

			char* result = analyzeRectangle(x1, x2, x3, x4, y1, y2, y3, y4);

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Testx2andx3areequal) //testing to see of the system recognizes x2 and x3 are equal 
		{
			int x1 = 3;
			int y1 = 1;
			int x2 = 3;
			int y2 = 6;
			int x3 = 3;
			int y3 = 6;
			int x4 = 6;
			int y4 = 1;
			char* expected = "4 points do not form a rectangle. Try again!\n";

			char* result = analyzeRectangle(x1, x2, x3, x4, y1, y2, y3, y4);

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Testx2andx4areequal) //testing that the system recognizes that x2 and x4 are equal
		{
			int x1 = 3;
			int y1 = 1;
			int x2 = 3;
			int y2 = 6;
			int x3 = 6;
			int y3 = 6;
			int x4 = 3;
			int y4 = 1;
			char* expected = "4 points do not form a rectangle. Try again!\n";

			char* result = analyzeRectangle(x1, x2, x3, x4, y1, y2, y3, y4);

			Assert::AreEqual(expected, result); 
		}

		TEST_METHOD(Testthaty3andy4areequal) //testing to see if system recognozes that y3 and y4 are equal
		{
			int x1 = 3;
			int y1 = 1;
			int x2 = 3;
			int y2 = 6;
			int x3 = 6;
			int y3 = 6;
			int x4 = 6;
			int y4 = 6;
			char* expected = "4 points do not form a rectangle. Try again!\n";

			char* result = analyzeRectangle(x1, x2, x3, x4, y1, y2, y3, y4);

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Testy4andy2areequal) //testing to see of system recognizes that y2 and y4 are equal 
		{
			int x1 = 3;
			int y1 = 1;
			int x2 = 3;
			int y2 = 6;
			int x3 = 6;
			int y3 = 6;
			int x4 = 6;
			int y4 = 6;
			char* expected = "4 points do not form a rectangle. Try again!\n";

			char* result = analyzeRectangle(x1, x2, x3, x4, y1, y2, y3, y4);

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Testtoseeifsquare) //testing to see of the points are a square
		{
			int x1 = 3;
			int y1 = 1;
			int x2 = 3;
			int y2 = 6;
			int x3 = 8;
			int y3 = 6;
			int x4 = 8;
			int y4 = 1;
			char* expected = "your rectangle is a square. Try again!\n";

			char* result = analyzeRectangle(x1, x2, x3, x4, y1, y2, y3, y4);

			Assert::AreEqual(expected, result);
		}
	};
}
