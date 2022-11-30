
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
			printf_s("Rectangle selected.\n"); //Users can enter their points in any order they want and the program will connect them without any crossover - this means that we completed the more points option 
			getRectanglePoints(points, NUMPOINT);

			POINTS vector12 = vectors(points[1], points[0]); 
			POINTS vector14 = vectors(points[3], points[0]); 
			POINTS vector13 = vectors(points[2], points[0]); 

			double dotproduct1214 = dotproduct(vector12, vector14); 
			double dotproduct1213 = dotproduct(vector12, vector13); 
			double dotproduct1314 = dotproduct(vector13, vector14); 

			double magnitude12 = magnitude(vector12); 
			double magnitude14 = magnitude(vector14); 
			double magnitude13 = magnitude(vector13); 

			double angle1 = angle(dotproduct1214, magnitude12, magnitude14);
			double angle2 = angle(dotproduct1213, magnitude12, magnitude13); 
			double angle3 = angle(dotproduct1314, magnitude13, magnitude14); 

			if (angle1 > angle2 && angle1 > angle3) //the program finds the largest angle between the three vectors (made up of the four points they entered) and connects the three points that make up the angle. This means that the connected points will not cross
			{
				POINTS point2 = points[0];
				POINTS point1 = points[1];
				POINTS point3 = points[3];
				POINTS point4 = points[2];

			
				doThesePointsMakeARectangle(point1, point2, point3, point4); //this function finds the distance between these points, determines if these distances make up a rectangle and prints if they are a rectangle or not. I added this function to make the program more repetitive

			}
			else if (angle2 > angle1 && angle2 > angle3)
			{
				POINTS point2 = points[0];
				POINTS point1 = points[1];
				POINTS point3 = points[2];
				POINTS point4 = points[3];

				doThesePointsMakeARectangle(point1, point2, point3, point4);

			}
			else if (angle3 > angle1 && angle3 > angle2)
			{
				POINTS point2 = points[0];
				POINTS point1 = points[2];
				POINTS point3 = points[3];
				POINTS point4 = points[1];

				doThesePointsMakeARectangle(point1, point2, point3, point4);
			}
			break;
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





//Original rectangle function - this one is the lower points option 
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