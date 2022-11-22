#include "rectangleSolver.h"


void getRectanglePoints(struct rectanglepoints pointarr[], int n)
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
				break;
			}
		}

		if (i == 1)
		{
			printf("(x<0 and y>0):\n");
			if ((scanf_s("%lf %lf", &pointarr[i].point_x, &pointarr[i].point_y) != 2) || ((pointarr[i].point_x > 0) || (pointarr[i].point_y < 0)))
			{
				puts("Invalid input, please try again");
				break;
			}
		}

		if (i == 2)
		{
			printf("(x<0 and y<0):\n");
			if ((scanf_s("%lf %lf", &pointarr[i].point_x, &pointarr[i].point_y) != 2) || ((pointarr[i].point_x > 0) || (pointarr[i].point_y > 0)))
			{
				puts("Invalid input, please try again");
				break;
			}
		}

		if (i == 3)
		{
			printf("(x>0 and y<0):\n");
			if ((scanf_s("%lf %lf", &pointarr[i].point_x, &pointarr[i].point_y) != 2) || ((pointarr[i].point_x < 0) || (pointarr[i].point_y > 0)))
			{
				puts("Invalid input, please try again");
				break;
			}
		}

	}
}

double rectangleDist(struct rectanglepoints p, struct rectanglepoints q) 
{
	return (p.point_x - q.point_x) * (p.point_x - q.point_x) + (p.point_y - q.point_y) * (p.point_y - q.point_y);
}

void isRectangle(struct rectanglepoints pointarr[])
{ 
	double dist12 = rectangleDist(pointarr[0], pointarr[1]);     
	double dist23 = rectangleDist(pointarr[1], pointarr[2]);
	double dist34 = rectangleDist(pointarr[2], pointarr[3]);
	double dist14 = rectangleDist(pointarr[0], pointarr[3]);
	double dist24 = rectangleDist(pointarr[1], pointarr[3]);
	double dist13 = rectangleDist(pointarr[0], pointarr[2]);

	if (dist12 == dist34 && dist14 == dist23 && dist24 == dist13 && dist12 != dist14) {
		printf("\nThe points you entered make a rectangle.\nThe area of this rectange is %0.4lf.\nThe perimiter of this rectangle is %0.4lf\n", CalculateArea(dist12, dist14), perimeterRectangle(dist12, dist23, dist34, dist14));
	}
	else
		printf("\nThe points you entered do not make a rectangle.\n");
}



double perimeterRectangle(double sideLengthA, double sideLengthB, double sideLengthC, double sideLengthD)

{
	double perimeter = sideLengthA + sideLengthB + sideLengthC + sideLengthD;
	//printf("the perimeter of the rectangle is: %0.2f ", perimeter); // what unit are we using?
	return perimeter;
}


double CalculateArea(double dista, double distb)
{
	double area = (dista * distb);
	return area;
}
