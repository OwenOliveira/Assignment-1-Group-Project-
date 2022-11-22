
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
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			anglesOfTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			break;

		case 2:  //added case 2 to the switch statement for the rectangle
			printf_s("Rectangle selected.\n");
			getRectanglePoints(points, NUMPOINT);

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


