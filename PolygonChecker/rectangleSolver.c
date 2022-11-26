#include "rectangleSolver.h"


bool getRectanglePoints(POINTS pointarr[], int n)
{
	puts("Enter your 4 points: ");
	for (int i = 0; i < n; i++)
	{

		printf("Point %d (x,y) for quadrant %d ", i + 1, i + 1);

		if (i == 0)
		{
			printf("(x>0 and y>0):\n");
			if ((scanf_s("%lf %lf", &pointarr[i].point_x, &pointarr[i].point_y) != 2) || ((pointarr[i].point_x < 0) || (pointarr[i].point_y < 0)))
			{
				puts("Invalid input, please try again");
				return false;
			}
		}

		if (i == 1)
		{
			printf("(x<0 and y>0):\n");
			if ((scanf_s("%lf %lf", &pointarr[i].point_x, &pointarr[i].point_y) != 2) || ((pointarr[i].point_x > 0) || (pointarr[i].point_y < 0)))
			{
				puts("Invalid input, please try again");
				return false;
			}
		}

		if (i == 2)
		{
			printf("(x<0 and y<0):\n");
			if ((scanf_s("%lf %lf", &pointarr[i].point_x, &pointarr[i].point_y) != 2) || ((pointarr[i].point_x > 0) || (pointarr[i].point_y > 0)))
			{
				puts("Invalid input, please try again");
				return false;
			}
		}

		if (i == 3)
		{
			printf("(x>0 and y<0):\n");
			if ((scanf_s("%lf %lf", &pointarr[i].point_x, &pointarr[i].point_y) != 2) || ((pointarr[i].point_x < 0) || (pointarr[i].point_y > 0)))
			{
				puts("Invalid input, please try again");
				return false;
			}
		}
	}
	return true;
}

double rectangleDist(POINTS p, POINTS q)
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
