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



float perimeterRectangle(float sideLengthA, float sideLengthB, float sideLengthC, float sideLengthD)

{
	float perimeter = sideLengthA + sideLengthB + sideLengthC + sideLengthD;
	printf("the perimeter of the rectangle is: %0.2f ", perimeter); // what unit are we using?
}



