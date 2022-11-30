
#include "menu.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"

int side = 0;

int main() {

	struct rectanglepoints points[NUMPOINT] = { 0,0 };        //array of structures, initialized to zero

	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			double triangleSides[3] = { 0, 0, 0 };
			double* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* resulttriangle = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", resulttriangle);
			anglesOfTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			break;

		case 2:  //added case 2 to the switch statement for the rectangle
			printf_s("Rectangle selected.\n");
			//if (getRectanglePoints(points, NUMPOINT))
			//{
			//	double dist12 = rectangleDist(points[0], points[1]);
			//	double dist23 = rectangleDist(points[1], points[2]);
			//	double dist34 = rectangleDist(points[2], points[3]);
			//	double dist14 = rectangleDist(points[0], points[3]);
			//	double dist24 = rectangleDist(points[1], points[3]);
			//	double dist13 = rectangleDist(points[0], points[2]);

			//	char* resultrectangle = isRectangle(dist12, dist34, dist14, dist23, dist24, dist13);


			//	if (resultrectangle == "The points do NOT make a rectangle")
			//	{
			//		printf_s("%s\n", resultrectangle);
			//		printf("\nThe perimeter of this shape is: %.2lf\n", perimeterRectangle(dist12, dist23, dist34, dist14));

			//	}
			//	else
			//	{
			//		printf_s("%s\n", resultrectangle);
			//		printf("\nThe area of this rectangle is: %.2lf\nThe perimeter of this rectangle is %.2lf\n", CalculateArea(dist12, dist14), perimeterRectangle(dist12, dist23, dist34, dist14));
			//	}
			//}
			break;
		case 3:
			printf_s("Rectangle - more points option - selected.\n");
			getRectanglePoints(points, NUMPOINT);
			
			printf("Vectors\n");
			POINTS vector12 = vectors(points[1], points[0]); // { points[1].point_x - points[0].point_x, points[1].point_y - points[0].point_y };
			printf("(%f, %f)\n", vector12.point_x, vector12.point_y);
			POINTS vector14 = vectors(points[3], points[0]); // { points[3].point_x - points[0].point_x, points[3].point_y - points[0].point_y };
			printf("(%f, %f)\n", vector14.point_x, vector14.point_y);
			POINTS vector13 = vectors(points[2], points[0]); // { points[2].point_x - points[0].point_x, points[2].point_y - points[0].point_y };
			printf("(%f, %f)\n", vector13.point_x, vector13.point_y);

			printf("Dotproducts\n");
			double dotproduct1214 = dotproduct(vector12, vector14); // , POINTS b)
			printf("%f\n", dotproduct1214);
			double dotproduct1213 = dotproduct(vector12, vector13); // (vector12.point_x * vector13.point_x) + (vector12.point_y * vector13.point_y);
			printf("%f\n", dotproduct1213);
			double dotproduct1314 = dotproduct(vector13, vector14); // (vector13.point_x * vector14.point_x) + (vector13.point_y * vector14.point_y);
			printf("%f\n", dotproduct1314);

			printf("Magnitudes\n");
			double magnitude12 = magnitude(vector12); // sqrt((vector12.point_x * vector12.point_x) + (vector12.point_y * vector12.point_y));
			printf("%f\n", magnitude12);
			double magnitude14 = magnitude(vector14); // sqrt((vector14.point_x * vector14.point_x) + (vector14.point_y * vector14.point_y));
			printf("%f\n", magnitude14);
			double magnitude13 = magnitude(vector13); // sqrt((vector13.point_x * vector13.point_x) + (vector13.point_y * vector13.point_y));
			printf("%f\n", magnitude13);

			printf("angles\n");
			double angle1 = angle(dotproduct1214, magnitude12, magnitude14); // acos(dotproduct1214 / ((magnitude12) * (magnitude14)));// AngleBetweenVectors(dotprod12, dist12, dist14);
			printf("%g\n", angle1);

			double angle2 = angle(dotproduct1213, magnitude12, magnitude13); // acos(dotproduct1213 / ((magnitude12) * (magnitude13))); //AngleBetweenVectors(dotprod13, dist12, dist13);
			printf("%g\n", angle2);
			double angle3 = angle(dotproduct1213, magnitude12, magnitude13); // acos(dotproduct1314 / ((magnitude13) * (magnitude14))); //AngleBetweenVectors(dotprod23, dist13, dist14);
			printf("%g\n", angle3);

			//Find largest

			if (angle1 > angle2 && angle1 > angle3)
			{
				POINTS point2 = points[0];
				POINTS point1 = points[1];
				POINTS point3 = points[2];
				POINTS point4 = points[3];

				double dist12 = rectangleDist(points[0], points[1]);
				double dist23 = rectangleDist(points[1], points[2]);
				double dist34 = rectangleDist(points[2], points[3]);
				double dist14 = rectangleDist(points[0], points[3]);
				double dist24 = rectangleDist(points[1], points[3]);
				double dist13 = rectangleDist(points[0], points[2]);

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
			else if (angle2 > angle1 && angle2 > angle3)
			{
				POINTS point2 = points[0];
				POINTS point1 = points[1];
				POINTS point3 = points[3];
				POINTS point4 = points[2];

				double dist12 = rectangleDist(points[0], points[1]);
				double dist23 = rectangleDist(points[1], points[2]);
				double dist34 = rectangleDist(points[2], points[3]);
				double dist14 = rectangleDist(points[0], points[3]);
				double dist24 = rectangleDist(points[1], points[3]);
				double dist13 = rectangleDist(points[0], points[2]);

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
			else if (angle3 > angle1 && angle3 > angle2)
			{
				POINTS point2_ = points[0];
				POINTS point1_ = points[2];
				POINTS point3_ = points[3];
				POINTS point4_ = points[1];

				double dist12 = rectangleDist(points[0], points[1]);
				double dist23 = rectangleDist(points[1], points[2]);
				double dist34 = rectangleDist(points[2], points[3]);
				double dist14 = rectangleDist(points[0], points[3]);
				double dist24 = rectangleDist(points[1], points[3]);
				double dist13 = rectangleDist(points[0], points[2]);

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
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}


