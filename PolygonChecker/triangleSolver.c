#include <stdio.h>
#include <stdbool.h>

#include "triangleSolver.h"


double* getTriangleSides(double* triangleSides) {
	printf_s("Enter the three sides of the triangle\n");
	for (int i = 0; i < 3; i++)
	{
		do
		{
			// display the side that a user enters
			if (i == 0)
				printf("First side(a): ");
			else if (i == 1)
				printf("Second side(b): ");
			else
				printf("Third side(c): ");

			if (scanf_s("%lf", &triangleSides[i]) != true)		// if a user enters something that is not a number,
			{													// display error msg and clear the buffer for the next input. 
				puts("Invalid input. Please try again.");		// 
				rewind(stdin);
			}
			else
				break;											// if the user enters valid input break the loop (Note. I don't want to use 'break', please give me some ideas)
		} while (true);											// Break is fine here, If it was steves class maybe no but in this scenario it works okay 
	}
	return triangleSides;										// return the triangle array that the user entered
}

double longestSide(double a, double b, double c) {				// this is the function that distinguishes which side has the longest length in the triangle.
	double tmplongest;											// declare a double variable that holds longest length of trianle sides.
	if (a >= b && a >= c)										// if side a is bigger than or equal to side b and side c, longest side is a.
	{
		tmplongest = a;
	}
	else if (b >= a && b >= c)									// if side b is bigger than or equal to side a and side c, longest side is .
		tmplongest = b;
	else														// else side c is the longest
		tmplongest = c;

	return tmplongest;											// return longest length.
}


char* analyzeTriangle(double a, double b, double c) {
	char* result = "";
	// each side cannot be negative number, and the length of one side cannot be equal to or greater than the combined length of the other two sides.
	if (a <= 0 || b <= 0 || c <= 0 ||longestSide(a, b, c) >= ((a + b + c) - longestSide(a, b, c)))
	{
		result = "Not a triangle\n";
	}
	else if (a == b && a == c) 
	{
		result = "Equilateral triangle\n";
	}
	else if ((a == b && a != c) || (a == c && a != b))
	{
		result = "Isosceles triangle\n";
	}
	else {
		result = "Scalene triangle\n";
	}

	return result;
}


double anglesOfTriangle(double a, double b, double c)
{
	double angleA, angleB, angleC;
	const double AnglePi = 180.0 / 3.1415926;

	if (a > 0 || b > 0 || c > 0 || longestSide(a, b, c) < ((a + b + c) - longestSide(a, b, c)))		// angles will be calculated when only it's a triangle,
	{
		angleA = acos(((b * b) + (c * c) - (a * a)) / (2.0 * b * c)) * AnglePi;
		angleB = acos(((a * a) + (c * c) - (b * b)) / (2.0 * a * c)) * AnglePi;
		angleC = 180.0 - (angleA + angleB);

		printf("The angle \"A\" is %g dgree.\n", angleA);
		printf("The angle \"B\" is %g dgree.\n", angleB);
		printf("The angle \"C\" is %g dgree.\n", angleC);

		return angleA + angleB + angleC;
	}
	else									// else ruturn 0
		return 0.0;

	printf("The angle \"A\" is %g dgree.\n", angleA);
	printf("The angle \"B\" is %g dgree.\n", angleB);
	printf("The angle \"C\" is %g dgree.\n", angleC);

	return angleA, angleB, angleC;
}