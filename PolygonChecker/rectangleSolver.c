#include "rectangleSolver.h"
//#include <cmath>

bool getRectanglePoints(POINTS pointarr[], int n)  //getRectanglePoints function definition, the points can be entered in any order
{
	puts("Enter your 4 points: "); //they can enter the points in any order they want
	for (int i = 0; i < n; i++)
	{
		printf("Point %d (x,y)\n", i+1);

		if (i == 0)
		{
			if ((scanf_s("%lf %lf", &pointarr[i].point_x, &pointarr[i].point_y) != 2)) 
			{
				while (getchar() != '\n');
				puts("Invalid input, please try again");
				return false;
			}
		}

		if (i == 1)
		{
			if ((scanf_s("%lf %lf", &pointarr[i].point_x, &pointarr[i].point_y) != 2) )
			{
				while (getchar() != '\n');
				puts("Invalid input, please try again");
				return false;
			}

			else
			{
				if(((pointarr[i].point_x == pointarr[i - 1].point_x) && (pointarr[i].point_y == pointarr[i - 1].point_y)))
				{
					puts("Please do not enter one point twice");
					return false;
				}
			}
		}

		if (i == 2)
		{
			if ((scanf_s("%lf %lf", &pointarr[i].point_x, &pointarr[i].point_y) != 2)) 
			{
				while (getchar() != '\n');
				puts("Invalid input, please try again");
				return false;
			}

			else
			{
				if (((pointarr[i].point_x == pointarr[i - 1].point_x) && (pointarr[i].point_y == pointarr[i - 1].point_y)) ||
					((pointarr[i].point_x == pointarr[i - 2].point_x) && (pointarr[i].point_y == pointarr[i - 2].point_y)))
				{
					puts("Please do not enter one point twice");
					return false;
				}
			}
		}

		if (i == 3)
		{
			if ((scanf_s("%lf %lf", &pointarr[i].point_x, &pointarr[i].point_y) != 2)) 
			{
				while (getchar() != '\n');
				puts("Invalid input, please try again");
				return false;
			}

			else
			{
				if (((pointarr[i].point_x == pointarr[i - 1].point_x) && (pointarr[i].point_y == pointarr[i - 1].point_y)) ||
					((pointarr[i].point_x == pointarr[i - 2].point_x) && (pointarr[i].point_y == pointarr[i - 2].point_y)) || 
					((pointarr[i].point_x == pointarr[i - 3].point_x) && (pointarr[i].point_y == pointarr[i - 3].point_y)))
				{
					puts("Please do not enter one point twice");
					return false;
				}
			}
		}
	}
	return true;
}

double rectangleDist(POINTS p, POINTS q) //line connecting these points 
{
	return sqrt((p.point_x - q.point_x) * (p.point_x - q.point_x) + (p.point_y - q.point_y) * (p.point_y - q.point_y));
}


char* isRectangle(double distA, double distB, double distC, double distD, double distE, double distF)
{ 
	if ((distA == distB) && (distC == distD) && (distE == distF) && (distA != distC))
		return "The points make a rectangle";
	else
		return "The points do NOT make a rectangle";
}


double perimeterRectangle(double sideLengthA, double sideLengthB, double sideLengthC, double sideLengthD)

{
	double perimeter = sideLengthA + sideLengthB + sideLengthC + sideLengthD;
	return perimeter;
}


double CalculateArea(double dista, double distb)
{
	double area = (dista * distb);
	return area;
}

POINTS vectors(POINTS a, POINTS b)
{
	POINTS vectors = { a.point_x - b.point_x, a.point_y - b.point_y };
	return vectors;
}

double dotproduct(POINTS a, POINTS b)
{
	double dotproduct = (a.point_x * b.point_x) + (a.point_y * b.point_y);
		return dotproduct;
}

double magnitude(POINTS a)
{
	double magnitude = sqrt((a.point_x * a.point_x) + (a.point_y * a.point_y));
	return magnitude;
}

double angle(double dotprod, double magA, double magB)
{
	double angle = acos(dotprod / ((magA) * (magB)));
	return angle;
} 


void doThesePointsMakeARectangle(POINTS a, POINTS b, POINTS c, POINTS d)
{
	double dist12 = rectangleDist(a, b);
	double dist23 = rectangleDist(b, c);
	double dist34 = rectangleDist(c, d);
	double dist14 = rectangleDist(a, d);
	double dist24 = rectangleDist(b, d);
	double dist13 = rectangleDist(a, c);

	char* resultrectangle = isRectangle(dist12, dist34, dist14, dist23, dist24, dist13);

	if (resultrectangle == "The points do NOT make a rectangle")
	{
		printf_s("%s\n", resultrectangle);
		printf("\nThe perimeter of this shape is: %.2lf\n", perimeterRectangle(dist12, dist23, dist34, dist14));

	}
	else
	{
		printf_s("%s\n", resultrectangle);
		printf("\nThe area of this rectangle is: %.2lf\nThe perimeter of this rectangle is %.2lf\n", CalculateArea(dist12, dist14), perimeterRectangle(dist12, dist23, dist34, dist14));
	}
}




