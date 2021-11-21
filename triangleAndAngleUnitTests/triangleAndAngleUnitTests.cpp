#include "pch.h"
#include "CppUnitTest.h"

extern "C" char* analyzeTriangle(int side1, int side2, int side3); 
extern "C" char* analyzeAngles(int a, int b, int c);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace triangleAndAngleUnitTests
{
	//Unit tests for triangles 
	
	TEST_CLASS(triangleUnitTests)
	{
	public:
		
		TEST_METHOD(zeroInputs) //All zero inputs do not form a triangle 
		{
			//arrange
			int triangleSide1 = 0; 
			int triangleSide2 = 0; 
			int triangleSide3 = 0; 
			char* EXPECTED = "Not a triangle"; 

			//act
			char* result = analyzeTriangle(triangleSide1, triangleSide2, triangleSide3); 

			//assert
			Assert::AreEqual(EXPECTED, result); 
		}
		TEST_METHOD(negativeInputs) //All negative inputs do not form a triangle 
		{
			//arrange
			int triangleSide1 = -3;
			int triangleSide2 = -4;
			int triangleSide3 = -5;
			char* EXPECTED = "Not a triangle";

			//act
			char* result = analyzeTriangle(triangleSide1, triangleSide2, triangleSide3);

			//assert
			Assert::AreEqual(EXPECTED, result);
		}
		TEST_METHOD(equalInputs) //All equal inputs form an equilateral triangle 
		{
			//arrange
			int triangleSide1 = 10;
			int triangleSide2 = 10;
			int triangleSide3 = 10;
			char* EXPECTED = "Equilateral triangle";

			//act
			char* result = analyzeTriangle(triangleSide1, triangleSide2, triangleSide3);

			//assert
			Assert::AreEqual(EXPECTED, result);
		}
		TEST_METHOD(twoEqualOneUniqueInputs) //Two equal inputs and one unique input form an isosceles triangle 
		{
			//arrange
			int triangleSide1 = 5;
			int triangleSide2 = 5;
			int triangleSide3 = 10;
			char* EXPECTED = "Isosceles triangle";

			//act
			char* result = analyzeTriangle(triangleSide1, triangleSide2, triangleSide3);

			//assert
			Assert::AreEqual(EXPECTED, result);
		}
		TEST_METHOD(oneUniqueTwoEqualInputs) //One unique input and two equal inputs form an isosceles triangle 
		{
			//arrange
			int triangleSide1 = 5;
			int triangleSide2 = 10;
			int triangleSide3 = 5;
			char* EXPECTED = "Isosceles triangle";

			//act
			char* result = analyzeTriangle(triangleSide1, triangleSide2, triangleSide3);

			//assert
			Assert::AreEqual(EXPECTED, result);
		}
		TEST_METHOD(uniqueInputs) //All unique inputs form a scalene triangle 
		{
			//arrange
			int triangleSide1 = 5;
			int triangleSide2 = 6;
			int triangleSide3 = 7;
			char* EXPECTED = "Scalene triangle";

			//act
			char* result = analyzeTriangle(triangleSide1, triangleSide2, triangleSide3);

			//assert
			Assert::AreEqual(EXPECTED, result);
		}
		TEST_METHOD(largeInputs) //All large inputs form a scalene triangle 
		{
			//arrange
			int triangleSide1 = 100100100;
			int triangleSide2 = 200200200;
			int triangleSide3 = 300300300;
			char* EXPECTED = "Scalene triangle";

			//act
			char* result = analyzeTriangle(triangleSide1, triangleSide2, triangleSide3);

			//assert
			Assert::AreEqual(EXPECTED, result);
		}
	};


	//Unit tests for angles 

	TEST_CLASS(angleUnitTests)
	{
	public:

		TEST_METHOD(zeroInputs) //All zero inputs do not form a regular closed triangle 
		{
			//arrange
			int triangleSide1 = 0;
			int triangleSide2 = 0;
			int triangleSide3 = 0;
			int EXPECTED2 = 0; 
			char* EXPECTED1 = "Unable to return inside angles as the dimensions you have entered do not form a regular closed triangle"; 

			//act
			char* angles = analyzeAngles(triangleSide1, triangleSide2, triangleSide3); 

			//assert
			Assert::AreEqual(EXPECTED2, strcmp(angles, EXPECTED1));
		}
		TEST_METHOD(negativeInputs) //All negative inputs do not form a regular closed triangle 
		{
			//arrange
			int triangleSide1 = -3;
			int triangleSide2 = -4;
			int triangleSide3 = -5;
			int EXPECTED1 = 0;
			char* EXPECTED2 = "Unable to return inside angles as the dimensions you have entered do not form a regular closed triangle";

			//act
			char* angles = analyzeAngles(triangleSide1, triangleSide2, triangleSide3); 

			//assert
			Assert::AreEqual(EXPECTED1, strcmp(angles, EXPECTED2));
		}
		TEST_METHOD(equalInputs) //All equal inputs form an equilateral triangle 
		{
			//arrange
			int triangleSide1 = 10;
			int triangleSide2 = 10;
			int triangleSide3 = 10;
			int EXPECTED1 = 0;
			char* EXPECTED2 = "Angle A is 60.000000 degrees\nAngle B is 60.000000 degrees\nAngle C is 60.000000 degrees";

			//act
			char* angles = analyzeAngles(triangleSide1, triangleSide2, triangleSide3);

			//assert
			Assert::AreEqual(EXPECTED1, strcmp(angles, EXPECTED2));
		}
		TEST_METHOD(twoEqualOneUniqueInputs) //Two equal inputs and one unique input do not form correct angles 
		{
			//arrange
			int triangleSide1 = 5;
			int triangleSide2 = 5;
			int triangleSide3 = 10;
			int EXPECTED1 = 0;
			char* EXPECTED2 = "Unable to return inside angles as the dimensions you have entered do not form a regular closed triangle";

			//act
			char* angles = analyzeAngles(triangleSide1, triangleSide2, triangleSide3);

			//assert
			Assert::AreEqual(EXPECTED1, strcmp(angles, EXPECTED2));
		}
		TEST_METHOD(oneUniqueTwoEqualInputs) //One unique input and two equal inputs do not form correct angles 
		{
			//arrange
			int triangleSide1 = 5;
			int triangleSide2 = 10;
			int triangleSide3 = 5;
			int EXPECTED1 = 0;
			char* EXPECTED2 = "Unable to return inside angles as the dimensions you have entered do not form a regular closed triangle";

			//act
			char* angles = analyzeAngles(triangleSide1, triangleSide2, triangleSide3);

			//assert
			Assert::AreEqual(EXPECTED1, strcmp(angles, EXPECTED2));
		}
		TEST_METHOD(uniqueInputs) //All unique inputs form a scalene triangle 
		{
			//arrange
			int triangleSide1 = 5;
			int triangleSide2 = 6;
			int triangleSide3 = 7;
			int EXPECTED1 = 0;
			char* EXPECTED2 = "Angle A is 44.415306 degrees\nAngle B is 57.121647 degrees\nAngle C is 78.463043 degrees";

			//act
			char* angles = analyzeAngles(triangleSide1, triangleSide2, triangleSide3);

			//assert
			Assert::AreEqual(EXPECTED1, strcmp(angles, EXPECTED2));
		}
		TEST_METHOD(largeInputs) //All large inputs form a scalene triangle 
		{
			//arrange
			int triangleSide1 = 100100100;
			int triangleSide2 = 200200200;
			int triangleSide3 = 300300300;
			int EXPECTED1 = 0;
			char* EXPECTED2 = "Unable to return inside angles as the dimensions you have entered do not form a regular closed triangle";

			//act
			char* angles = analyzeAngles(triangleSide1, triangleSide2, triangleSide3);

			//assert
			Assert::AreEqual(EXPECTED1, strcmp(angles, EXPECTED2));
		}
	};
}
