
#include "menu.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"

int side = 0;

int main() {

	struct rectanglepoints points[NUMPOINT];        //array of structures

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
			getRectanglePoints(points, NUMPOINT);

			double dist12 = rectangleDist(points[0], points[1]);
			double dist23 = rectangleDist(points[1], points[2]);
			double dist34 = rectangleDist(points[2], points[3]);
			double dist14 = rectangleDist(points[0], points[3]);
			double dist24 = rectangleDist(points[1], points[3]);
			double dist13 = rectangleDist(points[0], points[2]);

			if (!isRectangle(dist12, dist34, dist14, dist23, dist24, dist13))
				printf("The points you entered do not make a rectangle.\nThe perimeter of these points is %lf\n", perimeterRectangle(dist12, dist23, dist34, dist14));  
			else
				printf("\nThe points you entered make a rectangle.\nThe area of this rectangle is % lf\nThe perimeter of this rectangle is % lf\n", CalculateArea(dist12, dist14), perimeterRectangle(dist12, dist23, dist34, dist14)); 
			
			
			/*char* ifrectangle = analyzeRectangle(points);
			printf_s("%s\n", ifrectangle);*/
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


