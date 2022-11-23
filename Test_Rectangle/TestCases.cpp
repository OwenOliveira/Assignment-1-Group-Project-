#include "pch.h"
#include "CppUnitTest.h"

extern "C" void isRectangle(POINTS pointarr[]);
extern "C" double perimeterRectangle(double, double, double, double);
extern "C" double CalculateArea(double dista, double distb);
extern "C" char* analyzeTriangle(int side1, int side2, int side3);
extern "C" void anglesOfTriangle(int a, int b, int c);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCases
{
	TEST_CLASS(TestCases)
	{
	public:
		
		TEST_METHOD(FourPointsFunctionality)
		{
			POINTS points[SIZE] = { {5,2}, {-5,2}, {-5,-2}, {5,-2} };
			//This is testing the rectangle feature, whether the points form a rectangle or not (should form a rectangle in this case)
			/*char* result = isRectangle(points);*/
			/*Assert::AreEqual("Is rectangle", result);*/
		}
		
		TEST_METHOD(FourPointsFunctionality)
		{
			POINTS points[SIZE] = { {5,6}, {-5,2}, {-5,-4}, {5,-2} };
			//This is testing the rectangle feature, whether the points form a rectangle or not (should not form a rectangle in this case)
			/*char* result = isRectangle(points);
			char* result = isRectangle(points);*/
			/*Assert::AreEqual("Is not a rectangle", result);*/
		}
		
		/*TEST_METHOD(TestMethod3)
		{
		}
		
		TEST_METHOD(TestMethod4)
		{
		}*/
	};
}



//  triangle test cases - please note the AnglesOfTriangle function appears to need correction. 

namespace TriangleSolver
{
	TEST_CLASS(TriangleSolver) // testing analyzeTriangle
	{
	public:
		
		TEST_METHOD(Test1_analyzeTriangle_Equilateral_true)
		{
			int side1;
			int side2;
			int side3;
			char* result;

			side1 = 4;
			side2 = 4;
			side3 = 4;

			result = analyzeTriangle(side1, side2, side3);

			Assert::AreEqual("Equilateral triangle", result);
		}

		TEST_METHOD(Test2_analyzeTriangle_Equilateral_false)
		{
			int side1;
			int side2;
			int side3;
			char* result;

			side1 = 4;
			side2 = 7;
			side3 = 4;

			result = analyzeTriangle(side1, side2, side3);

			Assert::AreNotEqual("Equilateral triangle", result);
		}

		TEST_METHOD(Test3_analyzeTriangle_Isosoles_true)
		{
			int side1;
			int side2;
			int side3;
			char* result;

			side1 = 5;
			side2 = 5;
			side3 = 3;

			result = analyzeTriangle(side1, side2, side3);

			Assert::AreEqual("Isosoles triangle", result);
		}

		TEST_METHOD(Test4_analyzeTriangle_Equilateral_false)
		{
			int side1;
			int side2;
			int side3;
			char* result;

			side1 = 4;
			side2 = 4;
			side3 = 4;

			result = analyzeTriangle(side1, side2, side3);

			Assert::AreNotEqual("Equilateral triangle", result);
		}


		TEST_METHOD(Test5_analyzeTriangle_Scalene_true)
		{
			int side1;
			int side2;
			int side3;
			char* result;

			side1 = 4;
			side2 = 5;
			side3 = 6;

			result = analyzeTriangle(side1, side2, side3);

			Assert::AreEqual("Scalene triangle", result);
		}

		TEST_METHOD(Test1_analyzeTriangle_Scalene_false)
		{
			int side1;
			int side2;
			int side3;
			char* result;

			side1 = 4;
			side2 = 4;
			side3 = 9;

			result = analyzeTriangle(side1, side2, side3);

			Assert::AreNotEqual("Scalene triangle", result);
		}


		TEST_METHOD(Test1_analyzeTriangle_notTriangle_true)
		{
			int side1;
			int side2;
			int side3;
			char* result;

			side1 = 4;
			side2 = 4;
			side3 = -1;

			result = analyzeTriangle(side1, side2, side3);

			Assert::AreEqual("Not A Triangle", result);
		}

		TEST_METHOD(Test1_analyzeTriangle_notTriangle_false) // is a triangle but false for this. 
		{
			int side1;
			int side2;
			int side3;
			char* result;

			side1 = 4;
			side2 = 4;
			side3 = 4;

			result = analyzeTriangle(side1, side2, side3);

			Assert::AreNotEqual("Not A Triangle", result);
		}

	};

//
namespace AnglesOfTriangle
{
	TEST_CLASS(AnglesOfTriangle) // testing angles of triange for 180 (equilateral sides)
	{
	public:
 
		TEST_METHOD(Test1_AnglesOfTrianglesTest_Equilateral_true)
		{
 
			float side1 = 6;  // i feel like these should be float because it is math
			float side2 = 6;
			float side3 = 6;

			float result = getAnglesOfTriangle(side1, side2, side3);

			int sum = 180.f;
 
			Assert::AllAreEqual(sum, result);
		}


		//TEST_METHOD(Test1_AnglesOfTrianglesTest_ _true)  // next test here 
		//{

		//	float side1 = ;  // i feel like these should be float because it is math
		//	float side2 = ;
		//	float side3 = ;

		//	float result = getAnglesOfTriangle(side1, side2, side3);

		//	float sum = 180.f;

		//	Assert::AllAreEqual(sum, result);
		//}
	}


}