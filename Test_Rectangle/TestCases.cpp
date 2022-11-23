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
