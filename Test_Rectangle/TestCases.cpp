#include "pch.h"
#include "CppUnitTest.h"

extern "C" char* isRectangle(double distA, double distB, double distC, double distD, double distE, double distF);
extern "C" double rectangleDist(POINTS p, POINTS q);
extern "C" double perimeterRectangle(double, double, double, double);
extern "C" double CalculateArea(double dista, double distb);
extern "C" char* analyzeTriangle(double a, double b, double c);
extern "C" double anglesOfTriangle(double a, double b, double c);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCases
{
	TEST_CLASS(RectangleTestCases)
	{
	public:
		
		TEST_METHOD(Test1_isRectangle_Functionality)  
		{
			//Testing the isRectangle function, whether the points form a rectangle or not (should form a rectangle in this case)

			POINTS points[SIZE] = { {5,2}, {-5,2}, {-5,-2}, {5,-2} };

			double dist12 = rectangleDist(points[0], points[1]);
			double dist23 = rectangleDist(points[1], points[2]);
			double dist34 = rectangleDist(points[2], points[3]);
			double dist14 = rectangleDist(points[0], points[3]);
			double dist24 = rectangleDist(points[1], points[3]);
			double dist13 = rectangleDist(points[0], points[2]);

			char* result = isRectangle(dist12, dist34, dist14, dist23, dist24, dist13);
			Assert::AreEqual("The points make a rectangle", result);
		}
		
		TEST_METHOD(Test2_isRectangle_Functionality)
		{
			//This is testing the isRectangle function, whether the points form a rectangle or not (should NOT form a rectangle in this case)
			
			POINTS points[SIZE] = { {6,2}, {-5,2}, {-5,-2}, {5,-2} };

			double dist12 = rectangleDist(points[0], points[1]);
			double dist23 = rectangleDist(points[1], points[2]);
			double dist34 = rectangleDist(points[2], points[3]);
			double dist14 = rectangleDist(points[0], points[3]);
			double dist24 = rectangleDist(points[1], points[3]);
			double dist13 = rectangleDist(points[0], points[2]);

			char* result = isRectangle(dist12, dist34, dist14, dist23, dist24, dist13);
			Assert::AreEqual("The points do NOT make a rectangle", result);
		}


	};
}



//  triangle test cases - please note the AnglesOfTriangle function appears to need correction. 


namespace TestCases
{
	TEST_CLASS(TriangleTypeTestCases) // testing analyzeTriangle
	{
	public:
		TEST_METHOD(Test1_analyzeTriangle_Functionality) // testing for Equilateral triangle
		{
			/*This is testing the analyzeTriangle function, whether the given sides form a triangle or not, 
			if yes what kind of triangle (should NOT form a triangle in this case)*/
			
			int side1;
			int side2;
			int side3;
			char* result;

			side1 = 4;
			side2 = 4;
			side3 = -1;

			result = analyzeTriangle(side1, side2, side3);

			Assert::AreEqual("Not a triangle\n", result);
		}

		TEST_METHOD(Test2_analyzeTriangle_Functionality) 
		{
			/*This is testing the analyzeTriangle function, whether the given sides form a triangle or not,
			if yes what kind of triangle (should form a triangle in this case)*/

			int side1;
			int side2;
			int side3;
			char* result;

			side1 = 4;
			side2 = 4;
			side3 = 4;

			result = analyzeTriangle(side1, side2, side3);

			Assert::AreNotEqual("Not a triangle\n", result);
		}
		TEST_METHOD(Test3_analyzeTriangle_Functionality)
		{
			/*This is testing the analyzeTriangle function, whether the given sides form a triangle or not,
			if yes what kind of triangle (should form an equilateral triangle in this case)*/

			int side1;
			int side2;
			int side3;
			char* result;

			side1 = 4;
			side2 = 4;
			side3 = 4;

			result = analyzeTriangle(side1, side2, side3);

			Assert::AreEqual("Equilateral triangle\n", result);
		}

		TEST_METHOD(Test4_analyzeTriangle_Equilateral_Functionality)
		{
			/*This is testing the analyzeTriangle function, whether the given sides form a triangle or not,
			if yes what kind of triangle (should NOT form an equilateral triangle in this case)*/

			int side1;
			int side2;
			int side3;
			char* result;

			side1 = 4;
			side2 = 7;
			side3 = 4;

			result = analyzeTriangle(side1, side2, side3);

			Assert::AreNotEqual("Equilateral triangle\n", result);
		}

		TEST_METHOD(Test5_analyzeTriangle_Isosoles_Functionality)
		{
			/*This is testing the analyzeTriangle function, whether the given sides form a triangle or not,
			if yes what kind of triangle (should form an isosceles triangle in this case)*/

			int side1;
			int side2;
			int side3;
			char* result;

			side1 = 5;
			side2 = 5;
			side3 = 3;

			result = analyzeTriangle(side1, side2, side3);

			Assert::AreEqual("Isosceles triangle\n", result);
		}

		TEST_METHOD(Test6_analyzeTriangle_Isosoles_Functionality_True)
		{
			/*This is testing the analyzeTriangle function, whether the given sides form a triangle or not,
		    if yes what kind of triangle (should form an isosceles triangle in this case)*/

			int side1;
			int side2;
			int side3;
			char* result;

			side1 = 5;
			side2 = 8;
			side3 = 5;

			result = analyzeTriangle(side1, side2, side3);

			Assert::AreEqual("Isosceles triangle\n", result);
		}

		TEST_METHOD(Test7_analyzeTriangle_Isosoles_Functionality)
		{
			/*This is testing the analyzeTriangle function, whether the given sides form a triangle or not,
		    if yes what kind of triangle (should NOT form an isosceles triangle in this case)*/

			int side1;
			int side2;
			int side3;
			char* result;

			side1 = 5;
			side2 = 8;
			side3 = 7;

			result = analyzeTriangle(side1, side2, side3);

			Assert::AreNotEqual("Isosceles triangle\n", result);
		}


		TEST_METHOD(Test8_analyzeTriangle_Scalene_Functionality)
		{
			/*This is testing the analyzeTriangle function, whether the given sides form a triangle or not,
		    if yes what kind of triangle (should form a scalene triangle in this case)*/

			int side1;
			int side2;
			int side3;
			char* result;

			side1 = 4;
			side2 = 5;
			side3 = 6;

			result = analyzeTriangle(side1, side2, side3);

			Assert::AreEqual("Scalene triangle\n", result);
		}

		TEST_METHOD(Test9_analyzeTriangle_Scalene_Functionality_False)
		{
			/*This is testing the analyzeTriangle function, whether the given sides form a triangle or not,
			if yes what kind of triangle (should NOT form a scalene triangle in this case)*/

			int side1;
			int side2;
			int side3;
			char* result;

			side1 = 4;
			side2 = 4;
			side3 = 9;

			result = analyzeTriangle(side1, side2, side3);

			Assert::AreNotEqual("Scalene triangle\n", result);
		}
	};
}

namespace AnglesOfTriangle
{
	TEST_CLASS(AnglesOfTriangle) // testing angles of triange for 180 (equilateral sides)
	{
	public:
		TEST_METHOD(Test1_AnglesOfTrianglesTest_Equilateral_true)
		{

			double side1 = 6.0;
			double side2 = 6.0;
			double side3 = 6.0;

			double result = anglesOfTriangle(side1, side2, side3);

			double sum = 180.0;

			Assert::AreEqual(sum, result);
		}

		TEST_METHOD(Test2_AnglesOfTrianglesTest_Equilateral_false)
		{

			double side1 = 2.0;
			double side2 = 2.0;
			double side3 = 4.0;

			double result = anglesOfTriangle(side1, side2, side3);

			double sum = 180.0;

			Assert::AreEqual(sum, result);
		}
		//Owen you can make more below or change above if you think its necessary

	};
}